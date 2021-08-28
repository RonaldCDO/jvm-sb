#include <iomanip>
#include <fstream>
#include <iostream>
#include <netinet/in.h>
#include <string.h>

#define magic_number 0xcafebabe

using namespace std;

int convert(char num[]) {
   int len = strlen(num);
   int base = 1;
   int temp = 0;
   for (int i=len-1; i>=0; i--) {
      if (num[i]>='0' && num[i]<='9') {
         temp += (num[i] - 48)*base;
         base = base * 16;
      }
      else if (num[i]>='A' && num[i]<='F') {
         temp += (num[i] - 55)*base;
         base = base*16;
      }
   }
   return temp;
}

class ClassFile {
    public:
        ifstream arquivo;
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

void ClassFile::carregarArquivo(char* nomeArquivo) {

    cout << nomeArquivo << "\n";
    this -> arquivo.open(nomeArquivo);

    if (this -> arquivo.is_open()) {
        cout << "Arquivo aberto com sucesso\n";
    } else {
        cout << "Falha ao abrir arquivo. Encerrando...\n";
    }
}

void ClassFile::lerNumeroMagico() {
    uint32_t buffer;
    arquivo.read(reinterpret_cast<char *>(&buffer), sizeof(buffer));

    /** htonl() - host to network long conversion:
     * realiza a conversao de inteiros multi-byte 
     * da ordem do host para a ordem da rede
     * ex: se o programa ler "bebafeca", esse comando corrige
     * a ordem para "cafebabe" 
     **/
    buffer = htonl(buffer);
    cafebabe = buffer;
    
    // captura configuracoes do cout para posterior restauracao 
    ios_base::fmtflags oldFlags = cout.flags();
    streamsize oldPrec = cout.precision();
    char oldFill = cout.fill();
    
    cout << "Magic: " << hex << cafebabe << "\n";
    
    // restaura configuracoes do cout apos o uso do parametro "hex"
    cout.flags(oldFlags);
    cout.precision(oldPrec);
    cout.fill(oldFill);

    if (cafebabe == magic_number) {
        cout << "O arquivo possui o número magico de um .class \n";
    }
}

void ClassFile::lerMinorMajor() {
    
    uint16_t buffer;

    arquivo.read(reinterpret_cast<char *>(&buffer), sizeof(buffer));
    buffer = htons(buffer);
    minor = buffer;

    arquivo.read(reinterpret_cast<char *>(&buffer), sizeof(buffer));
    buffer = htons(buffer);
    major = buffer;

    cout << "Version (major.minor): " << major << "." << minor << "\n";
}

int main(int argc, char* argv[]) {

    cout << "Você informou " << argc << " argumentos:\n";
    
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << '\n';
    }

    ClassFile cf;

    cf.carregarArquivo(argv[1]);
    if(cf.arquivo.is_open()) {
        cf.lerNumeroMagico();
        cf.lerMinorMajor();
    }

    return 0;
}