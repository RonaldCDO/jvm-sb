#include "classfile.h"

int main(int argc, char* argv[]) {

    if (argc == 1)
    std::cout << "Voce informou " << argc << " argumento: " << argv[0] <<std::endl;
    else 
    std::cout << "Voce informou " << argc << " argumentos: ";
    
    for (int i = 0; i < argc -1; i++) {
        std::cout << argv[i] << " ";
    }

    if (argc < 2)
    {
        std::cout<<"Arquivo a ser lido nao foi informado"<<std::endl;
    return 0;
    }
    
    ClassFile * cf = new ClassFile();

    cf->LoadFile(argv[1]);
    cf->ShowMagic();
    cf->ShowMinor();
    cf->ShowMajor();
    cf->ShowJavaVersion();
    cf->ShowAccessFlags();
    cf->ShowThisClass();
    cf->ShowSuperClass();
    cf->ShowInterfacesCount();
    cf->ShowFieldsCount();
    cf->ShowMethodsCount();
    cf->ShowAttributesCount();
    cf->ShowConstantPoolCount();
    cf->ShowConstantPool();
    cf->ShowInterfaces();
    cf->ShowFields();
    cf->ShowMethods();
    delete cf;

    return 0;
}