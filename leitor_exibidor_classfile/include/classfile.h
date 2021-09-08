#ifndef EXIBITOR
#define EXIBITOR


#include <iostream>
#include <iomanip>
#include <fstream>
// #include <netinet/in.h>
#include <string.h>
#include "constant_pool.h"
#include "fields.h"
#include "methods.h"
#include "attributes.h"
#include "data_class_format.h"

#define magic_number 0xcafebabe
#define ACC_PUBLIC_C 0x0001
#define ACC_FINAL_C 0x0010
#define ACC_SUPER_C 0x0020
#define ACC_INTERFACE_C 0x0200
#define ACC_ABSTRACT_C 0x0400
#define ACC_SYNTHETIC_C 0x1000
#define ACC_ANNOTATION_C 0x2000
#define ACC_ENUM_C 0x4000

void LoadFile(char* fileName);

class ClassFile {
    protected:
        std::ifstream file;
        u4 magic; 
        u2 minor_version;
        u2 major_version;
        u2 constant_pool_count;
        ConstantPool * constant_pool;
        u2 access_flags;
        u2 this_class;
        u2 super_class;
        u2 interfaces_count;
        u2 * interfaces;
        u2 fields_count;
        Fields * fields_table;
        u2 methods_count;
        Methods * methods_table;
        u2 attributes_count;
        AttributesTable * attributes_table;

        bool FileIsOpen();
        void ReadClassFile();
        void LoadConstantPool();
        void LoadInterfaces();
        void LoadFieldsTable();
        void LoadMethodsTable();
        void LoadAttributesTable();
    public:
        void LoadFile(char* fileName);
        void ShowMagic();
        void ShowMinor();
        void ShowMajor();
        void ShowJavaVersion();
        void ShowConstantPoolCount();
        void ShowConstantPool();
        void ShowInterfaces();
        void ShowFields();
        void ShowMethods();
        void ShowAccessFlags();
        void ShowThisClass();
        void ShowSuperClass();
        void ShowInterfacesCount();
        void ShowInterfaces();
        void ShowFieldsCount();
        void ShowMethodsCount();
        void ShowAttributesCount();
        
        // u2 GetAcessFlags();
        // u2 GetThisClass();
        // u2 GetSuperClass();
        // u2 GetInterfacesCount();
        // u2 GetFieldsCount();
        // u2 GetMethodsCount();
        // u2 GetAttributesCount();
};

#endif
