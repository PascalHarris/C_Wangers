#include "c_wangers_uuid.h"

char* uuid_generator(int length) { // 0 or values greater than 56 result in full length UUID
    srand(time(NULL));
    char* strUuid = (char*)calloc(57, sizeof(char));
    sprintf(strUuid, "%x%x-%x-%x-%x-%x%x%x",
            rand(), rand(),
            rand(),
            ((rand() & 0x0fff) | 0x4000),
            rand() % 0x3fff + 0x8000,
            rand(), rand(), rand());
    if ((length > 0) && (length < 57)) {
        char* uuid2 = (char*)calloc(length+1, sizeof(char));
        strncpy(uuid2, strUuid, length);
        uuid2[length] = '\0';
        free(strUuid);
        return uuid2;
    }
    return strUuid;
}

char* generate_key(const int length) {
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    char* returnValue = (char*)malloc(sizeof(char) * length);

    for (int i = 0; i < length; ++i) {
        returnValue[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    returnValue[length] = '\0';

    return returnValue;
}
