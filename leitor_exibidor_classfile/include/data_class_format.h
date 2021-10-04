#ifndef FORMAT
#define FORMAT

#ifdef _WIN32
    #include <WinSock2.h>
#else
    #include <netinet/in.h>
#endif

#include <iomanip>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <vector>
#include <unordered_map>



typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;
typedef uint64_t u8;


// typedef unsigned char u1;
// typedef unsigned short u2;
// typedef unsigned int u4;


u1 Readu1(std::istream& file);

u1 * Readu1(std::istream& file, u2 length);

u1 * Readu1(std::istream& file, u4 length);

u2 Readu2(std::istream& file);

u2 Readu2Raw(std::istream& file);

u4 Readu4(std::istream& file);

u4 Readu4Raw(std::istream& file);

void Printu2Hex(u2 hex_value);

void Printu4Hex(u4 hex_value);

typedef union primitive_data{
    u1 *boolVal;
    u2 *charVal;
    u2 *shortVal;
    u4 *floatVal;
    u4 *integerVal;
    u8 *longVal;
    u8 *doubleVal;
    
} Primitive;

class JavaClassInstance;

class ArrayVariable;

// class ClassFile;

class Variable{

    enum dataType{
        voidType, byteType, boolType, charType, short_type, intType, floatType, longType,
        doubleType, classInstanceType, arrayType, stringType, returnAddressType 
    };

    union{
        Primitive *var;
        std::string *string;
        ArrayVariable *arr;
        u4 *returnAddress;
        // JavaClassInstance *object;
    };
};

// class JavaClassInstance{
//     ClassFile* readerJava;
//     std::unordered_map<std::string, Variable*> *fieldVariables;
// };

class ArrayVariable{
    std::vector<Variable*> arr;
};


union ulf
{
    unsigned long ul;
    float f;
};

#endif