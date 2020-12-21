#include <hash.h>

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define bytesInBlock 64
#define reservedBytes 8
#define digestLength 20

//Constant values and functions' names are almost identical to those specified in RFC 3174  

const uint32_t H[] = {
    0x67452301,
    0xEFCDAB89,
    0x98BADCFE,
    0x10325476,
    0xC3D2E1F0
};

const uint32_t K[] = {
    0x5A827999,
    0x6ED9EBA1,
    0x8F1BBCDC,
    0xCA62C1D6
};

static inline uint32_t f(size_t t, uint32_t B, uint32_t C, uint32_t D) {
    if(t < 20) return (B & C) | ((~B) & D);
    else if(t < 40) return B ^ C ^ D;
    else if(t < 60) return (B & C) | (B & D) | (C & D);
    else return B ^ C ^ D;
}

#define DEBUG

static inline unsigned char *pad(const unsigned char *op, size_t n) {
    int i, systemEndianCheck = 1;

    size_t bytesToPad = bytesInBlock - (n % bytesInBlock);
    if(bytesToPad <= reservedBytes) bytesToPad += bytesInBlock;

    unsigned char *rop = malloc(n + bytesToPad);
    memcpy(rop, op, n);
    memset(rop + n, 0x80, 1);
    memset(rop + n + 1, 0x00, bytesToPad - reservedBytes - 1);
    if(*(char *)&systemEndianCheck == 1) for(i = 0; i < reservedBytes; i++) *(rop + n + bytesToPad - 1 - i) = (unsigned char) (n >> 8 * i); //fuck little endian
    else memcpy(rop, &n, reservedBytes);

    #ifdef DEBUG 
    for(i = 0; i < n + bytesToPad; i++) printf("%02x", rop[i]);
    printf("\n");
    #endif

    return rop;
}

hashResult sha1(unsigned char *rop, const unsigned char *op, size_t n) {
    unsigned char *paddedMsg = pad(op, n);

    return hashSuccess;
}

