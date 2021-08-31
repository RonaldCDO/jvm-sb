#ifndef EXIBITOR
#define EXIBITOR

#include <iostream>
#include <iomanip>
#include <fstream>
#include <netinet/in.h>
#include <string.h>
#include "data_class_format.h"

#define magic_number 0xcafebabe

void LoadFile(char* fileName);

class ClassFile {
    private:
        std::ifstream file;
        u4 magic; 
        u2 minor_version;
        u2 major_version;
        u2 constant_pool_count;
        u1 * constant_pool_table;
        u2 acess_flags;
        u2 this_class;
        u2 super_class;
        u2 interfaces_count;
        u1 * interfaces_table;
        u2 fields_count;
        u1 * fields_table;
        u2 methods_count;
        u1 * methods_table;
        u2 attributes_count;
        u1 * attributes_table;

        void LoadFile(char* fileName);
        void GetMagic();
        void GetMinorAndMajor();
        u2 GetConstantPoolCount();
        u2 GetAcessFlags();
        u2 GetThisClass();
        u2 GetSuperClass();
        u2 GetInterfacesCount();
        u2 GetFieldsCount();
        u2 GetMethodsCount();
        u2 GetAttributesCount();
        void LoadConstantPoolTable();
};


// int ConvertToInt(char num[]);

#endif
