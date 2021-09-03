#include "leitor_exibidor.h"

// Leitura de 1 byte do arquivo
u1 ClassFile::Readu1() {

    u1 buffer_u1;
    
    file.read(reinterpret_cast<char *>(&buffer_u1), sizeof(buffer_u1));

    return buffer_u1;
}

// Leitura byte a byte de uma string de 'length' bytes
u1 * ClassFile::Readu1(u2 length) {

    u1* bytes = new u1[length+1];
    u1 buffer;
    
    for (int i = 0; i < length; i++) {
        file.read(reinterpret_cast<char *>(&buffer), sizeof(buffer));
        bytes[i] = buffer;
    }

    bytes[length] = '\0';

    return bytes;
}

// Leitura de 2 bytes do arquivo
u2 ClassFile::Readu2() {

    u2 buffer_u2;
    
    file.read(reinterpret_cast<char *>(&buffer_u2), sizeof(buffer_u2));

    buffer_u2 = htons(buffer_u2);
    
    return buffer_u2;
}

u2 ClassFile::Readu2Raw() {

    u2 buffer_u2;
    
    file.read(reinterpret_cast<char *>(&buffer_u2), sizeof(buffer_u2));
    
    return buffer_u2;
}

// Leitura de 4 bytes do arquivo
u4 ClassFile::Readu4() {

    u4 buffer_u4;
    
    file.read(reinterpret_cast<char *>(&buffer_u4), sizeof(buffer_u4));

    /** htonl() - host to network long conversion:
     * realiza a conversao de inteiros multi-byte 
     * da ordem do host para a ordem da rede
     * ex: se o programa ler "bebafeca", esse comando corrige
     * a ordem para "cafebabe" 
     **/
    buffer_u4 = htonl(buffer_u4);
    
    return buffer_u4;
    
}

void Printu2Hex(u2 hex_value) {

    // captura configuracoes do std::cout para posterior restauracao 
    std::ios_base::fmtflags oldFlags = std::cout.flags();
    std::streamsize oldPrec = std::cout.precision();
    char oldFill = std::cout.fill();
    
    std::cout << "0x" << std::uppercase << std::setfill('0') << std::setw(4) << std::hex << hex_value << std::endl;
    
    // restaura configuracoes do cout apos o uso do parametro "hex"
    std::cout.flags(oldFlags);
    std::cout.precision(oldPrec);
    std::cout.fill(oldFill);
}

void Printu4Hex(u4 hex_value) {

    // captura configuracoes do std::cout para posterior restauracao 
    std::ios_base::fmtflags oldFlags = std::cout.flags();
    std::streamsize oldPrec = std::cout.precision();
    char oldFill = std::cout.fill();
    
    std::cout << "0x" <<  std::uppercase <<std::setfill('0') << std::setw(8) << std::hex << hex_value << std::endl;
    
    // restaura configuracoes do cout apos o uso do parametro "hex"
    std::cout.flags(oldFlags);
    std::cout.precision(oldPrec);
    std::cout.fill(oldFill);
}

void ClassFile::LoadFile(char* fileName){
    std::cout << fileName << "\n";

    this -> file.open(fileName);
    std::cout<<"Filename: " << fileName <<std::endl;

    if (this -> file.is_open()) {
        ReadClassFile();
    } else {
        std::cout << "Falha ao abrir arquivo. Encerrando...\n";
    }
}

bool ClassFile::FileIsOpen() {
    if (file.is_open()) {
        return true;
    }

    return false;
}

void ClassFile::ReadClassFile(){
    magic = Readu4();

    if (magic == magic_number) 
        std::cout << "File Type: .class"<<"\n";
    else{
        std::cout<< "Tipo de arquivo não aceito\n";
        exit(1);
    }
    minor_version = Readu2();
    major_version = Readu2();
    constant_pool_count = Readu2();

    LoadConstantPool();

    access_flags = Readu2Raw();
    this_class = Readu2Raw();
    super_class = Readu2Raw();
    interfaces_count = Readu2();

    /**
    LoadInterfacesTable();

    fields_count = Readu2();

    LoadFieldsTable();
    
    methods_count = Readu2();   

    LoadMethodsTable();

    attributes_count = Readu2();

    LoadAttributesTable();
    **/
}

void ClassFile::ShowMagic() {

    std::cout << "Magic: ";
    Printu4Hex(magic);
}

void ClassFile::ShowMinor() {
    std::cout << "Minor Version:\t\t" << minor_version << std::endl;
}

void ClassFile::ShowMajor() {
    std::cout << "Major Version:\t\t" << major_version << std::endl;
}

void ClassFile::ShowConstantPoolCount(){
    std::cout << "Constant Pool count:\t" << constant_pool_count << std::endl;
}

void ClassFile::ShowAccessFlags() {
    std::cout << "Flags:\t\t";
    Printu2Hex(access_flags);
}

void ClassFile::ShowThisClass() {
    std::cout << "This_class:\t\t" << this_class << std::endl;
}

void ClassFile::ShowSuperClass() {
    std::cout << "Super_class:\t\t" << super_class << std::endl;
}

u2 ClassFile::GetAcessFlags(){
    return access_flags;
}

void ClassFile::LoadConstantPool() {

    u2 cp_count_local = constant_pool_count;


    constant_pool = new ConstantPool();

    u1 tag;
    u2 length;
    u1 * bytes;

    while(cp_count_local) {

        tag = Readu1();

        switch(unsigned(tag)) {
            case CLASS:
                //std::cout << "Class_type" << std::endl;
                constant_pool->AppendClass(tag, Readu2());;
                break;
            case FIELD_REF:
                //std::cout << "FieldRef_type" << std::endl;
                constant_pool->AppendFieldRef(tag, Readu2(), Readu2());
                break;
            case METHOD_REF:
                //std::cout << "MethodRef_type" << std::endl;
                constant_pool->AppendMethodRef(tag, Readu2(), Readu2());
                break;
            case INTERFACE_METHOD_REF:
                //std::cout << "InterfaceMethodRef_type" << std::endl;
                constant_pool->AppendInterfaceMethodRef(tag, Readu2(), Readu2());
                break;
            case STRING:
                //std::cout << "String_type" << std::endl;
                constant_pool->AppendString(tag, Readu2());
                break;
            case INTEGER:
                //std::cout << "Integer_type" << std::endl;
                constant_pool->AppendInt(tag, Readu4());
                break;
            case FLOAT:
                //std::cout << "Float_type" << std::endl;
                constant_pool->AppendFloat(tag, Readu4());
                break;
            case LONG:
                //std::cout << "Long_type" << std::endl;
                constant_pool->AppendLong(tag, Readu4(), Readu4());
                cp_count_local--;
                break;
            case DOUBLE:
                //std::cout << "Double_type" << std::endl;
                constant_pool->AppendDouble(tag, Readu4(), Readu4());
                cp_count_local--;
                break;
            case NAME_AND_TYPE:
                //std::cout << "NameAndType_type" << std::endl;
                constant_pool->AppendNameAndType(tag, Readu2(), Readu2());
                break;
            case UTF8:
                //std::cout << "Utf8_type" << std::endl;
                length = Readu2();
                //std::cout << length << std::endl;
                bytes = Readu1(length);
                constant_pool->AppendUtf8(tag, length, bytes);
                break;
            case METHOD_HANDLE:
                //std::cout << "MethodHandle_type" << std::endl;
                constant_pool->AppendMethodHandle(tag, Readu1(), Readu2());
                break;
            case METHOD_TYPE:
                //std::cout << "MethodType_type" << std::endl;
                constant_pool->AppendMethodType(tag, Readu2());
                break;
            case INVOKE_DYNAMIC:
                //std::cout << "InvokeDynamic_type" << std::endl;
                constant_pool->AppendInvokeDynamic(tag, Readu2(), Readu2());
                break;
        }

        cp_count_local--;
    }
}

void ClassFile::ShowConstantPool() {
    constant_pool->ShowConstantPoolTable();
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

