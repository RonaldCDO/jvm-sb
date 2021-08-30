#include <iostream>
#include <iomanip>
#include <fstream>
#include <netinet/in.h>
#include <string.h>

#define magic_number 0xcafebabe

void LoadFile(char* fileName);

class ClassFile {
    private:
        std::ifstream file;
        uint32_t magic; 
        uint16_t minor_version;
        uint16_t major_version;
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
    public:
        void LoadFile(char* fileName);
        std::ifstream * GetFile();
        void GetMagicNumber();
        void GetMinorMajor();
        void GetConstantPoolSize();
        void LoadConstantPool(int16_t cp_count);
        void GetFlags();
        void GetThis_class();
        void GetSuperClass();
        void GetInterfacesCount();
        void GetFieldsCount();
        void GetMethodsCount();
        void GetAttributesCount();
};

class ConstantPoolEntry {
    private:
        uint8_t tag;
        uint8_t info[];
    public: 
        void SetTag(uint8_t tag);
        int GetTag();
};


// int ConvertToInt(char num[]);