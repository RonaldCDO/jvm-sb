#include "leitor_exibidor.h"


// int ConvertToInt(char num[]){
//     int len = strlen(num);
//     int base = 1;
//     int temp = 0;
//     for (int i=len-1; i>=0; i--) {
//         if (num[i]>='0' && num[i]<='9') {
//             temp += (num[i] - 48)*base;
//             base = base * 16;
//         }
//         else if (num[i]>='A' && num[i]<='F') {
//             temp += (num[i] - 55)*base;
//             base = base*16;
//         }
//    }
//    return temp;
// }


void ClassFile::LoadFile(char* fileName){
    std::cout << fileName << "\n";

    this -> file.open(fileName);
    std::cout<<"Filename: " << fileName <<std::endl;

    if (this -> file.is_open() != true)
    //     std::cout << "Arquivo aberto com sucesso\n";
    // } else
        std::cout << "Falha ao abrir arquivo. Encerrando...\n";
    
}


void ClassFile::GetMagic(){
    u4 buffer;
    file.read(reinterpret_cast<char *>(&buffer), sizeof(buffer));

    /** htonl() - host to network long conversion:
     * realiza a conversao de inteiros multi-byte 
     * da ordem do host para a ordem da rede
     * ex: se o programa ler "bebafeca", esse comando corrige
     * a ordem para "cafebabe" 
     **/
    buffer = htonl(buffer);
    magic = buffer;
    
    // captura configuracoes do std::cout para posterior restauracao 
    std::ios_base::fmtflags oldFlags = std::cout.flags();
    std::streamsize oldPrec = std::cout.precision();
    char oldFill = std::cout.fill();
    
    std::cout << "Magic: " << std::hex << magic << "\n";
    
    // restaura configuracoes do cout apos o uso do parametro "hex"
    std::cout.flags(oldFlags);
    std::cout.precision(oldPrec);
    std::cout.fill(oldFill);

    if (magic == magic_number) 
        std::cout << "File Type: .class"<<"\n";
    else{
        std::cout<< "Tipo de arquivo não aceito\n";
        exit(1);
    }
}


void ClassFile::GetMinorAndMajor() {
    
    u2 buffer;

    file.read(reinterpret_cast<char *>(&buffer), sizeof(buffer));
    buffer = htons(buffer);
    minor_version = buffer;

    file.read(reinterpret_cast<char *>(&buffer), sizeof(buffer));
    buffer = htons(buffer);
    major_version = buffer;

    std::cout << "Minor Version:\t\t" << minor_version << std::endl;
    std::cout << "Major Version:\t\t" << major_version << std::endl;
}


u2 ClassFile::GetConstantPoolCount(){
    return constant_pool_count;
}


u2 ClassFile::GetAcessFlags(){
    return acess_flags;
}


u2 ClassFile::GetThisClass(){
    return this_class;
}


u2 ClassFile::GetSuperClass(){
    return super_class;
}


u2 ClassFile::GetInterfacesCount(){
    return interfaces_count;
}


u2 ClassFile::GetFieldsCount(){
    return fields_count;
}


u2 ClassFile::GetMethodsCount(){
    return methods_count;
}


u2 ClassFile::GetAttributesCount(){
    return attributes_count;
}


void ClassFile::LoadConstantPoolTable(){
    

}

