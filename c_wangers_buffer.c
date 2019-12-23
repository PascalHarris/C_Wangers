#include "c_wangers_buffer.h"

unsigned long ByteSwap64 (unsigned long LongNumber) {
    return (((LongNumber&0x00000000000000FFULL)<<56)+
            ((LongNumber&0x000000000000FF00ULL)<<40)+
            ((LongNumber&0x0000000000FF0000ULL)<<24)+
            ((LongNumber&0x00000000FF000000ULL)<<8)+
            ((LongNumber&0x000000FF00000000ULL)>>8)+
            ((LongNumber&0x0000FF0000000000ULL)>>24)+
            ((LongNumber&0x00FF000000000000ULL)>>40)+
            ((LongNumber&0xFF00000000000000ULL)>>56));
}

int ByteSwap32 (int Number) {
    return (((Number&0x000000FF)<<24)+
            ((Number&0x0000FF00)<<8)+
            ((Number&0x00FF0000)>>8)+
            ((Number&0xFF000000)>>24));
}

short ByteSwap16 (short Number) {
    return (((Number&0x00FF)<<8)+
            ((Number&0xFF00)>>8));
}

void dumpbits(char byte) {
    char finalhash[13]={'\0'};
    char hexval[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    unsigned char mask_table[] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };

    finalhash[0] = hexval[((byte >> 4) & 0xF)];
    finalhash[1] = hexval[byte & 0x0F];
    finalhash[2] = ' ';

    for (int iterator=0;iterator<8;iterator++) {
        if (( byte & mask_table[iterator] ) != 0x00) {
            finalhash[3 + iterator] = '1';
        } else {
            finalhash[3 + iterator] = '0';
        }
    }

    printf("%s ",finalhash);
}

unsigned long readU16( const unsigned char* ptr ) {
    return ptr[0]+(ptr[1]<<8);
}

unsigned long readU32( const unsigned char* ptr ) {
    return ptr[0]+(ptr[1]<<8)+(ptr[2]<<16)+(ptr[3]<<24);
}

void writeU16( unsigned char* ptr, unsigned long data ) {
    ptr[0] = (unsigned char)(data & 0xff);
    ptr[1] = (unsigned char)((data >> 8) & 0xff);
}

void writeU32( unsigned char* ptr, unsigned long data ) {
    ptr[0] = (unsigned char)(data & 0xff);
    ptr[1] = (unsigned char)((data >> 8) & 0xff);
    ptr[2] = (unsigned char)((data >> 16) & 0xff);
    ptr[3] = (unsigned char)((data >> 24) & 0xff);
}

unsigned char* buffer_from_hexstring(char* string, size_t* buffer_size) {
    *buffer_size = (strlen(string) * sizeof(unsigned char) / 2);
    unsigned char* HexBuffer = (unsigned char *)calloc( strlen(string), sizeof(unsigned char) ); // far too large - but Windows throws a strop if it's any smaller.
    
    size_t count = 0;
    while (count < *buffer_size) {
        sscanf(string, "%2hhx", &HexBuffer[count++]);
        string += 2;
    }
    
    return HexBuffer;
}

char* hexstring_from_buffer(unsigned char* buffer, size_t buffer_size) {
    int buffer_sz = (buffer_size * 2) + 1;
    char* HexString = (char *)calloc( buffer_sz, sizeof(char) );

    for (size_t count = 0; count < buffer_size; count++) {
        sprintf(HexString, "%s%02x", HexString, buffer[count]);
    }
    return HexString;
}

void * swap_bytes(void *input_bytes, size_t length) {
    unsigned int i;
    unsigned char *in = (unsigned char *)input_bytes, temp;

    for(i = 0; i < length / 2; i++) {
        temp = *(in + i);
        *(in + i) = *(in + length - i - 1);
        *(in + length - i - 1) = temp;
    }

    return input_bytes;
}

char *base64_decode(char *s) {
    char *p = s, *e, *r, *_ret;
    int len = strlen(s);
    unsigned char i, unit[4];

    e = s + len;
    len = len / 4 * 3 + 1;
    r = _ret = (char *) malloc(len);

    while (p < e) {
        memcpy(unit, p, 4);
        if (unit[3] == '=') {
            unit[3] = 0;
        }
        if (unit[2] == '=') {
            unit[2] = 0;
        }
        p += 4;

        for (i = 0; unit[0] != B64[i] && i < 64; i++) {
        }
        unit[0] = i == 64 ? 0 : i;
        for (i = 0; unit[1] != B64[i] && i < 64; i++) {
        }
        unit[1] = i == 64 ? 0 : i;
        for (i = 0; unit[2] != B64[i] && i < 64; i++) {
        }
        unit[2] = i == 64 ? 0 : i;
        for (i = 0; unit[3] != B64[i] && i < 64; i++) {
        }
        unit[3] = i == 64 ? 0 : i;
        *r++ = (unit[0] << 2) | (unit[1] >> 4);
        *r++ = (unit[1] << 4) | (unit[2] >> 2);
        *r++ = (unit[2] << 6) | unit[3];
    }
    *r = 0;

    return _ret;
}
