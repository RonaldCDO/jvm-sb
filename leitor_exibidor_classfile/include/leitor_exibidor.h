#include <iostream>
#include <iomanip>
#include <fstream>
#include <netinet/in.h>
#include <string.h>

#define magic_number 0xcafebabe
#define u4length 4

void carregarArquivo(char* nomeArquivo);

class ClassFile {
    public:
        std::ifstream arquivo;
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
        void carregarArquivo(char* nomeArquivo);
        void lerNumeroMagico();
        void lerMinorMajor();
};

int convert(char num[]);