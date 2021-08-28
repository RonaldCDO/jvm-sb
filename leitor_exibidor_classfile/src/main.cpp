#include "leitor_exibidor.h"

int main(int argc, char* argv[]) {

    std::cout << "Você informou " << argc << " argumentos:\n";
    
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << '\n';
    }

    carregarArquivo(argv[1]);

    return 0;
}