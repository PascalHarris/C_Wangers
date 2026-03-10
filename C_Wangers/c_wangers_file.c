#include "c_wangers_file.h"

char* expand_path(char* path) {
    wordexp_t exp_result;
    wordexp(path, &exp_result, 0);
    static char returnValue[LOCALPATHLENGTH];

    if (strlen(exp_result.we_wordv[0]) < LOCALPATHLENGTH) {
        sprintf(returnValue,"%s",exp_result.we_wordv[0]);
    }
    wordfree(&exp_result);
    return returnValue;
}

signed make_directory(char* path, mode_t mode) {
    if (mkdir(path, mode) == -1) {
        if( errno == EEXIST ) {
            return ALREADY_EXISTS;
        } else {
            printf ("Error creating folder %s\n",path);
        }
        return CREATE_FAILED;
    }
    return CREATE_SUCCESS;
}

bool file_exists (char* filename) {
    struct stat buffer;
    return (stat (filename, &buffer) == 0);
}

int line_count(char *filename) {
    FILE *fp = fopen(filename,"r");
    int ch = 0, lines = 0;
    
    if (fp) {
        while(!feof(fp)) {
            ch = fgetc(fp);
            if(ch == '\n') { lines++; }
        }
        fclose(fp);
        lines++;
    }
    return lines;
}
