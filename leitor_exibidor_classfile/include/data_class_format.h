#ifndef FORMAT
#define FORMAT

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef union primitive_data{
    uint8_t B;
    char C;
    double D;
    float F;
    int I;
    long J;
    short S;
    bool Z;
    
} primitive;

typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;

union ulf
{
    unsigned long ul;
    float f;
};


#endif