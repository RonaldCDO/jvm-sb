#include "leitor_exibidor.h"

int main(int argc, char* argv[]) {

    std::cout << "Você informou " << argc << " argumentos:\n";
    
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << '\n';
    }

    ClassFile cf;

    cf.carregarArquivo(argv[1]);
    if(cf.arquivo.is_open()) {
        cf.lerNumeroMagico();
        cf.lerMinorMajor();
    }

    return 0;
}