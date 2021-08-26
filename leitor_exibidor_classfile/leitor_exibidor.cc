#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define u4length 4

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