#include "c_wangers_uuid.h"

char* uuid_generator(int length) { // 0 or values greater than 56 result in full length UUID
    srand((unsigned int)time(NULL));
    char* strUuid = (char*)calloc(57, sizeof(char));
    sprintf(strUuid, "%x%x-%x-%x-%x-%x%x%x",
            arc4random(), arc4random(),
            arc4random(),
            ((arc4random() & 0x0fff) | 0x4000),
            arc4random() % 0x3fff + 0x8000,
            arc4random(), arc4random(), arc4random());
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

    char* returnValue = (char*)calloc(length, sizeof(char));

    for (int i = 0; i < length; ++i) {
        returnValue[i] = alphanum[arc4random() % (sizeof(alphanum) - 1)];
    }

    returnValue[length] = '\0';

    return returnValue;
}
