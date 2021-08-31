#include "leitor_exibidor.h"

u1 ClassFile::Readu1() {

    u1 buffer_u1;
    
    file.read(reinterpret_cast<char *>(&buffer_u1), sizeof(buffer_u1));

    buffer_u1 = htons(buffer_u1);
    
    return buffer_u1;
}

u2 ClassFile::Readu2() {

    u2 buffer_u2;
    
    file.read(reinterpret_cast<char *>(&buffer_u2), sizeof(buffer_u2));

    buffer_u2 = htons(buffer_u2);
    
    return buffer_u2;
    
}

u4 ClassFile::Readu4() {

    u4 buffer_u4;
    
    file.read(reinterpret_cast<char *>(&buffer_u4), sizeof(buffer_u4));

    buffer_u4 = htons(buffer_u4);
    
    return buffer_u4;
    
}

void ClassFile::LoadFile(char* fileName){
    std::cout << fileName << "\n";

    this -> file.open(fileName);
    std::cout<<"Filename: " << fileName <<std::endl;

    if (this -> file.is_open() != true)
    //     std::cout << "Arquivo aberto com sucesso\n";
    // } else
        std::cout << "Falha ao abrir arquivo. Encerrando...\n";
}

bool ClassFile::FileIsOpen() {
    if (file.is_open()) {
        return true;
    }

    return false;
}

void ClassFile::ReadMagic(){
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

    if (magic == magic_number) 
        std::cout << "File Type: .class"<<"\n";
    else{
        std::cout<< "Tipo de arquivo não aceito\n";
        exit(1);
    }
    
}

void ClassFile::ShowMagic() {

    // captura configuracoes do std::cout para posterior restauracao 
    std::ios_base::fmtflags oldFlags = std::cout.flags();
    std::streamsize oldPrec = std::cout.precision();
    char oldFill = std::cout.fill();
    
    std::cout << "Magic: " << std::hex << magic << "\n";
    
    // restaura configuracoes do cout apos o uso do parametro "hex"
    std::cout.flags(oldFlags);
    std::cout.precision(oldPrec);
    std::cout.fill(oldFill);

}


void ClassFile::ReadMinorAndMajor() {
    
    u2 buffer;

    // leitura de dados para esse buffer
    buffer = Readu2();
    
    // atribuicao do valor convertido a variavel de minor_version
    minor_version = buffer;

    // o processo se repete aqui para a major version
    buffer = Readu2();

    major_version = buffer;
}

void ClassFile::ShowMinor() {
    std::cout << "Minor Version:\t\t" << minor_version << std::endl;
}

void ClassFile::ShowMajor() {
    std::cout << "Major Version:\t\t" << major_version << std::endl;
}

void ClassFile::ReadConstantPoolSize(){

    u2 buffer;

    file.read(reinterpret_cast<char *>(&buffer), sizeof(buffer));

    constant_pool_count = htons(buffer);
}

void ClassFile::ShowConstantPoolCount(){
    std::cout << "Constant Pool count:\t" << constant_pool_count << std::endl;
}

u2 ClassFile::GetAcessFlags(){
    return acess_flags;
}

void ClassFile::LoadConstantPool() {

    u2 cp_count_local = constant_pool_count;

    ConstantPool cp;

    u1 tag;

    while(cp_count_local) {

        tag = Readu1();

        switch (tag)
        {
        case CLASS:
            // constant_pool.Append(Readu2());
            break;

        case FIELD_REF:
            
            break;
        
        case METHOD_REF:
            
            break;
        
        case INTERFACE_METHOD_REF:
            
            break;
        
        case STRING:
            
            break;
        
        case FLOAT:
            
            break;
        
        case LONG:
            
            break;
        
        case DOUBLE:
            
            break;
        
        case NAME_AND_TYPE:
            
            break;
        
        case UTF8:
            
            break;
        
        case METHOD_HANDLE:
            
            break;
        
        case METHOD_TYPE:
            
            break;        

        case INVOKE_DYNAMIC:
            
            break;
        
        default:
            break;
        }

        // cp

        std::cout << cp_count_local << std::endl;

        cp_count_local--;
    }

    this->constant_pool = cp;
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

