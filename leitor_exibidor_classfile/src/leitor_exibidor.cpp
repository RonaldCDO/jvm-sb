#include "leitor_exibidor.h"


int convert(char num[]){
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


void ClassFile::carregarArquivo(char* nomeArquivo){
    std::cout << nomeArquivo << "\n";

    this -> arquivo.open(nomeArquivo);

    if (this -> arquivo.is_open()) {
        std::cout << "Arquivo aberto com sucesso\n";
    } else
        std::cout << "Falha ao abrir arquivo. Encerrando...\n";
}


void ClassFile::lerNumeroMagico(){
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
    std::ios_base::fmtflags oldFlags = std::cout.flags();
    std::streamsize oldPrec = std::cout.precision();
    char oldFill = std::cout.fill();
    
    std::cout << "Magic: " << std::hex << cafebabe << "\n";
    
    // restaura configuracoes do cout apos o uso do parametro "hex"
    std::cout.flags(oldFlags);
    std::cout.precision(oldPrec);
    std::cout.fill(oldFill);

    if (cafebabe == magic_number) 
        std::cout << "O arquivo possui o número magico de um .class \n";
}


void ClassFile::lerMinorMajor() {
    
    uint16_t buffer;

    arquivo.read(reinterpret_cast<char *>(&buffer), sizeof(buffer));
    buffer = htons(buffer);
    minor = buffer;

    arquivo.read(reinterpret_cast<char *>(&buffer), sizeof(buffer));
    buffer = htons(buffer);
    major = buffer;

    std::cout << "Version (major.minor): " << major << "." << minor << "\n";
}
