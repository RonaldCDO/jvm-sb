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

// typedef union {
//         U1 * arr;
//         U1 u1;        
//         U2 u2;        
//         U4 u4;
        
// } ClassType;


#endif