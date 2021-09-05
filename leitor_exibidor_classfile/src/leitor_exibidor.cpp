#include "leitor_exibidor.h"

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
    magic = Readu4(file);
    

    if (magic == magic_number) 
        std::cout << "File Type: .class"<<"\n";
    else{
        std::cout<< "Tipo de arquivo não aceito\n";
        exit(1);
    }
    minor_version = Readu2(file);

    major_version = Readu2(file);

    constant_pool_count = Readu2(file);
      
    LoadConstantPool();

    access_flags = Readu2Raw(file);
    this_class = Readu2Raw(file);
    super_class = Readu2Raw(file);
    interfaces_count = Readu2Raw(file);

    LoadInterfaces();

    fields_count = Readu2Raw(file);

    LoadFieldsTable();

    methods_count = Readu2Raw(file);

    LoadMethodsTable();

    attributes_count = Readu2Raw(file);

    // LoadAttributesTable();

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
    std::cout << "Flags:\t\t\t";
    Printu2Hex(access_flags);

    u2 byte;

    byte = access_flags & 0x000F;

    if (byte == ACC_PUBLIC_C) std::cout << "\t\t\tACC_PUBLIC" << std::endl;

    byte = access_flags & 0x00F0;

    if (byte == ACC_FINAL_C) std::cout << "\t\t\tACC_FINAL" << std::endl;
    if (byte == ACC_SUPER_C) std::cout << "\t\t\tACC_SUPER" << std::endl;

    byte = access_flags & 0x0F00;

    if (byte == ACC_INTERFACE_C) std::cout << "\t\t\tACC_INTERFACE" << std::endl;
    if (byte == ACC_ABSTRACT_C) std::cout << "\t\t\tACC_ABSTRACT" << std::endl;

    byte = access_flags & 0xF000;

    if (byte == ACC_ANNOTATION_C) std::cout << "\t\t\tACC_ABSTRACT" << std::endl;
    if (byte == ACC_ENUM_C) std::cout << "\t\t\tACC_ABSTRACT" << std::endl;
}

void ClassFile::ShowThisClass() {
    std::cout << "This_class:\t\t" << this_class << std::endl;
}

void ClassFile::ShowSuperClass() {
    std::cout << "Super_class:\t\t" << super_class << std::endl;
}


void ClassFile::ShowInterfacesCount(){
    std::cout << "Interfaces:\t\t" << interfaces_count << std::endl;
}


void ClassFile::ShowFieldsCount(){
    std::cout << "Fields:\t\t\t" << fields_count << std::endl;
}


void ClassFile::ShowMethodsCount(){
    std::cout << "Methods:\t\t" << methods_count << std::endl;
}

void ClassFile::ShowAttributesCount(){
    std::cout <<"Attributes:\t\t" << attributes_count << std::endl;
}
// u2 ClassFile::GetAcessFlags(){
//     return access_flags;
// }

void ClassFile::LoadConstantPool() {

    u2 cp_count_local = constant_pool_count;


    constant_pool = new ConstantPool();

    u1 tag;
    u2 length;
    u1 * bytes;

    while(cp_count_local) {

        tag = Readu1(file);

        switch(unsigned(tag)) {
            case CLASS:
                //std::cout << "Class_type" << std::endl;
                constant_pool->AppendClass(tag, Readu2(file));;
                break;
            case FIELD_REF:
                //std::cout << "FieldRef_type" << std::endl;
                constant_pool->AppendFieldRef(tag, Readu2(file), Readu2(file));
                break;
            case METHOD_REF:
                //std::cout << "MethodRef_type" << std::endl;
                constant_pool->AppendMethodRef(tag, Readu2(file), Readu2(file));
                break;
            case INTERFACE_METHOD_REF:
                //std::cout << "InterfaceMethodRef_type" << std::endl;
                constant_pool->AppendInterfaceMethodRef(tag, Readu2(file), Readu2(file));
                break;
            case STRING:
                //std::cout << "String_type" << std::endl;
                constant_pool->AppendString(tag, Readu2(file));
                break;
            case INTEGER:
                //std::cout << "Integer_type" << std::endl;
                constant_pool->AppendInt(tag, Readu4(file));
                break;
            case FLOAT:
                //std::cout << "Float_type" << std::endl;
                constant_pool->AppendFloat(tag, Readu4(file));
                break;
            case LONG:
                //std::cout << "Long_type" << std::endl;
                constant_pool->AppendLong(tag, Readu4(file), Readu4(file));
                cp_count_local--;
                break;
            case DOUBLE:
                //std::cout << "Double_type" << std::endl;
                constant_pool->AppendDouble(tag, Readu4(file), Readu4(file));
                cp_count_local--;
                break;
            case NAME_AND_TYPE:
                //std::cout << "NameAndType_type" << std::endl;
                constant_pool->AppendNameAndType(tag, Readu2(file), Readu2(file));
                break;
            case UTF8:
                //std::cout << "Utf8_type" << std::endl;
                length = Readu2(file);
                //std::cout << length << std::endl;
                bytes = Readu1(file, length);
                constant_pool->AppendUtf8(tag, length, bytes);
                break;
            case METHOD_HANDLE:
                //std::cout << "MethodHandle_type" << std::endl;
                constant_pool->AppendMethodHandle(tag, Readu1(file), Readu2(file));
                break;
            case METHOD_TYPE:
                //std::cout << "MethodType_type" << std::endl;
                constant_pool->AppendMethodType(tag, Readu2(file));
                break;
            case INVOKE_DYNAMIC:
                //std::cout << "InvokeDynamic_type" << std::endl;
                constant_pool->AppendInvokeDynamic(tag, Readu2(file), Readu2(file));
                break;
        }

        cp_count_local--;
    }
}

void ClassFile::ShowConstantPool() {
    constant_pool->ShowConstantPoolTable();
}

void ClassFile::ShowFields() {

    if (fields_count) {
        
        std::cout << "Fields:" << std::endl;
        
        Fields_info* field;

        u2 byte;
        u2 flags;
        u2 index;
        u1 * descriptor_string;

        for (int i = 0; i < fields_count; i++) {
            field = fields_table->GetField(i);

            flags = field->GetAccessFlags();

            byte = flags & 0x000F;

            std::cout << "{\n" << std::endl;

            switch(byte){
                case ACC_PUBLIC_F:
                    std::cout << "public ";
                    break;
                case ACC_PROTECTED_F:
                    std::cout << "protected ";
                    break;
                case ACC_PRIVATE_F:
                    std::cout << "private ";
                    break;
            }

            index = field->GetDescriptorIndex();
            descriptor_string = constant_pool->GetUtf8(index);
            /**
            switch (descriptor_string[0]) {
                case ((int)"B"):
                    std:: 
            }**/
            std::cout << constant_pool->GetUtf8(index) << " ";

            index = field->GetNameIndex();
            std::cout << constant_pool->GetUtf8(index) << std::endl;

            std::cout << "\tFlags:" << std::endl;

            byte = flags & 0x000F;

            switch(byte){
                case ACC_PUBLIC_F:
                    std::cout << "\t\tACC_PUBLIC" << std::endl;
                    break;
                case ACC_PROTECTED_F:
                    std::cout << "\t\tACC_PROTECTED" << std::endl;
                    break;
                case ACC_PRIVATE_F:
                    std::cout << "\t\tACC_PRIVATE" << std::endl;
                    break;
                case ACC_STATIC_F:
                    std::cout << "\t\tACC_STATIC" << std::endl;
                    break;
            }

            byte = flags & 0x00F0;

            switch(byte){
                case ACC_FINAL_F:
                    std::cout << "\t\tACC_FINAL" << std::endl;
                    break;
                case ACC_VOLATILE_F:
                    std::cout << "\t\tACC_VOLATILE" << std::endl;
                    break;
                case ACC_TRANSIENT_F:
                    std::cout << "\t\tACC_TRANSIENT" << std::endl;
                    break;
            }

            byte = flags & 0x0F00;

                switch(byte){
                case ACC_SYNTHETIC_F:
                    std::cout << "\t\tACC_SYNTHETIC" << std::endl;
                    break;
                case ACC_ENUM_F:
                    std::cout << "\t\tACC_ENUM" << std::endl;
                    break;
            }
            std::cout << "}" << std::endl;

        }
    }

}

void ClassFile::ShowMethods() {

    if (methods_count) {
        
        std::cout << "Methods:" << std::endl;
        
        Methods_info* method;

        u2 byte;
        u2 flags;
        u2 index;

        for (int i = 0; i < methods_count; i++) {
            method = methods_table->GetMethod(i);

            flags = method->GetAccessFlags_M();

            byte = flags & 0x000F;

            std::cout << "\n" << std::endl;

            switch(byte){
                case ACC_PRIVATE_M:
                    std::cout << "private ";
                    break;
                case ACC_PROTECTED_M:
                    std::cout << "protected ";
                    break;
                case ACC_PUBLIC_M:
                    std::cout << "public ";
                    break;
            }

            index = method->GetDescriptorIndex_M();
            std::cout << constant_pool->GetUtf8(index) << " ";

            index = method->GetNameIndex_M();
            std::cout << constant_pool->GetUtf8(index) << std::endl;

            std::cout << "\tFlags:" << std::endl;

            byte = flags & 0x000F;

            switch(byte){
                case ACC_PUBLIC_M:
                    std::cout << "\t\tACC_PUBLIC" << std::endl;
                    break;
                case ACC_PROTECTED_M:
                    std::cout << "\t\tACC_PROTECTED" << std::endl;
                    break;
                case ACC_PRIVATE_M:
                    std::cout << "\t\tACC_PRIVATE" << std::endl;
                    break;
                case ACC_STATIC_M:
                    std::cout << "\t\tACC_STATIC" << std::endl;
                    break;
            }

            byte = flags & 0x00F0;

            switch(byte){
                case ACC_FINAL_M:
                    std::cout << "\t\tACC_FINAL" << std::endl;
                    break;
                case ACC_SYNCRONIZED_M:
                    std::cout << "\t\tACC_SYNCRONIZED" << std::endl;
                    break;
                case ACC_BRIDGE_M:
                    std::cout << "\t\tACC_BRIDGE" << std::endl;
                    break;
                  case ACC_VARARGS_M:
                    std::cout << "\t\tACC_VARARGS" << std::endl;
                    break;
                    
            }

            byte = flags & 0x0F00;

                switch(byte){
                case ACC_NATIVE_M:
                    std::cout << "\t\tACC_NATIVE" << std::endl;
                    break;
                case ACC_ABSTRACT_M:
                    std::cout << "\t\tACC_ABSTRACT" << std::endl;
                    break;
                case ACC_STRICT_M:
                    std::cout << "\t\tACC_STRICT" << std::endl;
                    break;
                case ACC_SYNTHETIC_M:
                    std::cout << "\t\tACC_SYNTHETIC" << std::endl;
                    break;
                

            }

            std::cout << "}" << std::endl;

        }
    }

}



void ClassFile::LoadInterfaces() {
    if (interfaces_count) {

        interfaces = new u2(interfaces_count);
        for (int i = 0; i < interfaces_count; i++) {
            interfaces[i] = Readu2Raw(file);
        }
    }
}

void ClassFile::LoadFieldsTable() {
    
    if (fields_count) {

    Fields_info * field_pt;
    u2 attribute_name_index;
    u4 attribute_length;
    u1 * att_info;
    
    

        fields_table = new Fields();

        for (int i = 0; i < fields_count; i++) {
            
            field_pt = new Fields_info(Readu2Raw(file), Readu2Raw(file), Readu2Raw(file), Readu2Raw(file));
            

            for (int j = 0; j < field_pt->GetAttributesCount(); j++) {
                attribute_name_index = Readu2Raw(file);
                u2 aux = Readu2Raw(file);
                u2 aux2 = Readu2Raw(file);
                attribute_length = aux + aux2;
                att_info = Readu1(file, attribute_length);
            }
            fields_table->appendField(field_pt);
        }
    }
}


void ClassFile::LoadMethodsTable() {
    
    if (methods_count) {

    Methods_info * methods_pt;
    u2 attribute_name_index;
    u4 attribute_length;
    u1 * att_info;

        methods_table = new Methods();

        for (int i = 0; i < methods_count; i++) {
            
            methods_pt = new Methods_info(Readu2Raw(file), Readu2Raw(file), Readu2Raw(file), Readu2Raw(file));

            for (int j = 0; j < methods_pt->GetAttributesCount_M(); j++) {
                attribute_name_index = Readu2Raw(file);
                u2 aux = Readu2Raw(file);
                u2 aux2 = Readu2Raw(file);
                attribute_length = aux + aux2;
                att_info = Readu1(file, attribute_length);
            }

            methods_table->AppendMethod(methods_pt);
        }
    }
}

// u2 ClassFile::GetThisClass(){
//     return this_class;
// }

// u2 ClassFile::GetSuperClass(){
//     return super_class;
// }


// u2 ClassFile::GetInterfacesCount(){
//     return interfaces_count;
// }


// u2 ClassFile::GetFieldsCount(){
//     return fields_count;
// }


// u2 ClassFile::GetMethodsCount(){
//     return methods_count;
// }


// u2 ClassFile::GetAttributesCount(){
//     return attributes_count;
// }    

