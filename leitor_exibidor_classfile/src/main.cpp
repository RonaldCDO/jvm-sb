/**
 * LEITOR EXIBIDOR DE BYTECODE JAVA
 * 
 * SOFTWARE BASICO 
 * PROF MARCELO LADEIRA
 * 
 * INTEGRANTES
 * RONALD CESAR OLIVEIRA - 18/0047205
 * JOAO ANTONIO MORAES - 16/0126975
 * GEOVANNE CHIAPINOTTO - 15/0059639
 * PEDRO AUGUSTO NUNES - 16/0141044
 * 
 **/

#include "classfile.h"

int main(int argc, char** argv) {

    
    if (argc == 1)
    std::cout << "Voce informou " << argc << " argumento: " << argv[0] <<std::endl;
    else 
    std::cout << "Voce informou " << argc << " argumentos: ";
    
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << " ";
    }

    if (argc < 2)
    {
        std::cout<<"Arquivo a ser lido nao foi informado"<<std::endl;
    return 0;
    }
    
    ClassFile * cf = new ClassFile();

    if (*argv[1] == 'e'){
        std::cout << "\nLEITOR/EXIBIDOR DE BYTECODE JAVA" << std::endl;
        
        char* fileName = argv[2];
        std::cout<<"\nFilename: " << fileName <<std::endl;

        cf->LoadFile(fileName);
        cf->ShowMagic();
        cf->ShowMinor();
        cf->ShowMajor();
        cf->ShowJavaVersion();
        cf->ShowAccessFlags();
        cf->ShowThisClass();
        cf->ShowSuperClass();
        cf->ShowFieldsCount();
        cf->ShowMethodsCount();
        cf->ShowAttributesCount();
        cf->ShowConstantPoolCount();
        cf->ShowConstantPool();
        cf->ShowInterfaces();
        cf->ShowFields();
        cf->ShowMethods();
        delete cf;
    } else if(*argv[1] == 'i'){
        char* fileName = argv[2];
        cf->LoadFile(fileName);
        std::cout<<"\n\nINTERPRETADOR DE BYTECODE JAVA"<<std::endl;
    }
    else{
        std::cout<<"Opcao desconhecida"<<std::endl;
    return 0;
    }
    

    return 0;
}