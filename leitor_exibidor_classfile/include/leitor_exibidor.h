#ifndef EXIBITOR
#define EXIBITOR

#ifdef _WIN32
    #include <WinSock2.h>
#else
    #include <netinet/in.h>
#endif

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include "constant_pool.h"



#define magic_number 0xcafebabe

void LoadFile(char* fileName);

class ClassFile {
    protected:
        std::ifstream file;
        u4 magic; 
        u2 minor_version;
        u2 major_version;
        u2 constant_pool_count;
        ConstantPool * constant_pool;
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
        u1 Readu1();
        u1 * Readu1(u2 length);
        u2 Readu2();
        u4 Readu4();
        bool FileIsOpen();
        void ReadClassFile();
        void LoadConstantPool();
        void LoadInterfacesTable();
        void LoadFieldsTable();
        void LoadMethodsTable();
        void LoadAttributesTable();
    public:
        void LoadFile(char* fileName);

        void ShowMagic();
        void ShowMinor();
        void ShowMajor();
        void ShowConstantPoolCount();
        void ShowConstantPool();
        u2 GetAcessFlags();
        u2 GetThisClass();
        u2 GetSuperClass();
        u2 GetInterfacesCount();
        u2 GetFieldsCount();
        u2 GetMethodsCount();
        u2 GetAttributesCount();
};


// int ConvertToInt(char num[]);

#endif
