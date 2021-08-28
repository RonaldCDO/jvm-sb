#include "leitor_exibidor.h"




void carregarArquivo(char* nomeArquivo){
    std::cout << nomeArquivo << "\n";
    std::ifstream arquivo;
    arquivo.open(nomeArquivo);

    if (arquivo.is_open()) {
        uint32_t u4;
        std::cout << "Arquivo aberto com sucesso\n";
        arquivo.read(reinterpret_cast<char *>(&u4), sizeof(u4));

        /**
        ios_base::fmtflags oldFlags = cout.flags();
        streamsize oldPrec = cout.precision();
        char oldFill = cout.fill();
        **/

        std::cout << "Magic: " << std::hex << u4 << "\n";

        /**
         * cout.flags(oldFlags);
        cout.precision(oldPrec);
        cout.fill(oldFill);
        **/

    } else {
        std::cout << "Falha ao abrir arquivo. Encerrando...\n";
    }
}
