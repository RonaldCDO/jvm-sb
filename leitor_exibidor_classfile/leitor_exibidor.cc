#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define u4length 4

class ClassFile {
    public:
        uint8_t ca;
        uint8_t fe;
        uint8_t ba;
        uint8_t be;
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
};

void carregarArquivo(char* nomeArquivo) {

    cout << nomeArquivo << "\n";
    ifstream arquivo;
    arquivo.open(nomeArquivo);

    if (arquivo.is_open()) {
        uint32_t u4;
        cout << "Arquivo aberto com sucesso\n";
        arquivo.read(reinterpret_cast<char *>(&u4), sizeof(u4));

        /**
        ios_base::fmtflags oldFlags = cout.flags();
        streamsize oldPrec = cout.precision();
        char oldFill = cout.fill();
        **/

        cout << "Magic: " << hex << u4 << "\n";

        /**
         * cout.flags(oldFlags);
        cout.precision(oldPrec);
        cout.fill(oldFill);
        **/

    } else {
        cout << "Falha ao abrir arquivo. Encerrando...\n";
    }
}

int main(int argc, char* argv[]) {

    cout << "Você informou " << argc << " argumentos:\n";
    
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << '\n';
    }

    carregarArquivo(argv[1]);

    return 0;
}