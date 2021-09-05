#include "data_class_format.h"

// Leitura de 1 byte do arquivo
u1 Readu1(std::istream& file) {

    u1 buffer_u1;
    
    file.read(reinterpret_cast<char *>(&buffer_u1), sizeof(buffer_u1));

    return buffer_u1;
}


// Leitura byte a byte de uma string de 'length' bytes
u1 * Readu1(std::istream& file, u2 length) {

    u1* bytes = new u1[length+1];
    u1 buffer;
    
    for (int i = 0; i < length; i++) {
        file.read(reinterpret_cast<char *>(&buffer), sizeof(buffer));
        bytes[i] = buffer;
    }

    bytes[length] = '\0';

    return bytes;
}

// Leitura byte a byte de uma cadeia de 'length' bytes
u1 * Readu1(std::istream& file, u4 length) {

    u1* bytes = new u1[length+1];
    u1 buffer;
    
    for (u4 i = 0; i < length; i++) {
        file.read(reinterpret_cast<char *>(&buffer), sizeof(buffer));
        bytes[i] = buffer;
    }

    return bytes;
}

// Leitura de 2 bytes do arquivo
u2 Readu2(std::istream& file) {

    u2 buffer_u2;
    
    file.read(reinterpret_cast<char *>(&buffer_u2), sizeof(buffer_u2));

    buffer_u2 = htons(buffer_u2);
    
    return buffer_u2;
}

//  Leitura de 2 bytes sem conversão de endianess
u2 Readu2Raw(std::istream& file) {

    u2 buffer_u2;
    
    file.read(reinterpret_cast<char *>(&buffer_u2), sizeof(buffer_u2));
    
    return buffer_u2;
}

// Leitura de 4 bytes do arquivo
u4 Readu4(std::istream& file) {

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


u4 Readu4Raw(std::istream& file) {

    u4 buffer_u4;
    
    file.read(reinterpret_cast<char *>(&buffer_u4), sizeof(buffer_u4));
    
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