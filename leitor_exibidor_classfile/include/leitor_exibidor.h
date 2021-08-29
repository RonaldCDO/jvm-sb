#include <iostream>
#include <iomanip>
#include <fstream>
#include <netinet/in.h>
#include <string.h>

#define magic_number 0xcafebabe

void LoadFile(char* fileName);


class ClassFile {
    public:
        std::ifstream file;
        uint32_t cafebabe;
        uint16_t minor;
        uint16_t major;
        uint16_t constant_pool_count;
        uint8_t * constant_pool_table;
        uint16_t acess_flags;
        uint16_t this_class;
        uint16_t super_class;
        uint16_t interface_count;
        uint8_t * interface_table;
        uint16_t field_count;
        uint8_t * field_table;
        uint16_t method_count;
        uint8_t * method_table;
        uint16_t attribute_count;
        uint8_t * attribute_table;

        void LoadFile(char* fileName);
        void GetMagicNumber();
        void GetMinorMajor();
        void GetFlags();
        void GetThis_class();
        void GetSuperClass();
        void GetInterfacesCount();
        void GetFieldsCount();
        void GetMethodsCount();
        void GetAttributesCount();
        void LoadConstantPool();
};


int ConvertToInt(char num[]);