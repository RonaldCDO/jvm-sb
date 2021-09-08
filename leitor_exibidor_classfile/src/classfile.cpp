#include "classfile.h"

void ClassFile::LoadFile(char* fileName){

    file.open(fileName, std::ios::binary);

    std::cout << fileName << "\n";

    std::cout<<"\nFilename: " << fileName <<std::endl;
    
    if (file.is_open()) {
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
        std::cout<< "Tipo de arquivo nao aceito\n";
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

     if (attributes_count) {
         attributes_table = new AttributesTable();
         attributes_table->LoadAttributesTable(file, attributes_count, constant_pool);
     }

    //std::cout << "Fim da leitura do arquivo .class." << std::endl; 
}


void ClassFile::LoadInterfaces() {
    if (interfaces_count) {

        interfaces = new u2(interfaces_count);
        for (int i = 0; i < interfaces_count; i++) {
            interfaces[i] = Readu2Raw(file);
        }
    }
}

void ClassFile::LoadConstantPool() {

    u2 cp_count_local = constant_pool_count -1;


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

void ClassFile::LoadFieldsTable() {
    
    if (fields_count) {

    FieldsInfo * field;    

        fields_table = new Fields();

        for (int i = 0; i < fields_count; i++) {
            
            field = new FieldsInfo(Readu2Raw(file), Readu2Raw(file), Readu2Raw(file), Readu2Raw(file));
            
            if (field->GetAttributesCount()) {
                AttributesTable* at = new AttributesTable();
                at->LoadAttributesTable(file, field->GetAttributesCount(), constant_pool);
                field->SetAttributesTable(at);
            }
            fields_table->appendField(field);
        }
    }
}


void ClassFile::LoadMethodsTable() {
    
    if (methods_count) {

    MethodsInfo * method;

        methods_table = new Methods();

        for (int i = 0; i < methods_count; i++) {

            method = new MethodsInfo(Readu2Raw(file), Readu2Raw(file), Readu2Raw(file), Readu2Raw(file));

            if (method->GetAttributesCount()) {
                AttributesTable * at = new AttributesTable();                
                at->LoadAttributesTable(file, method->GetAttributesCount(), constant_pool);
                method->SetAttributesTable(at);
            }

            methods_table->AppendMethod(method);
        }
    }
}
void ClassFile::ShowMagic() {

    std::cout << "Magic: ";
    Printu4Hex(magic);
    std::cout<<std::endl;
}

void ClassFile::ShowMinor() {
    std::cout << "Minor Version:\t\t" << minor_version << std::endl;
}

void ClassFile::ShowMajor() {
    std::cout << "Major Version:\t\t" << major_version << std::endl;
}

void ClassFile::ShowJavaVersion() {
    std::cout << "Java Version:\t\t" << "1." << major_version-44 << std::endl;
}

void ClassFile::ShowConstantPoolCount(){
    std::cout << "Constant Pool count:\t" << constant_pool_count << std::endl;
}

void ClassFile::ShowAccessFlags() {
    std::cout << "Flags: ";
    Printu2Hex(access_flags);

    u2 byte;

    byte = access_flags & 0x000F;

    if (byte == ACC_PUBLIC_C) std::cout << "\t\tACC_PUBLIC" << std::endl;

    byte = access_flags & 0x00F0;

    if (byte == ACC_FINAL_C) std::cout << "\t\tACC_FINAL" << std::endl;
    if (byte == ACC_SUPER_C) std::cout << "\t\tACC_SUPER" << std::endl;

    byte = access_flags & 0x0F00;

    if (byte == ACC_INTERFACE_C) std::cout << "\t\tACC_INTERFACE" << std::endl;
    if (byte == ACC_ABSTRACT_C) std::cout << "\t\tACC_ABSTRACT" << std::endl;

    byte = access_flags & 0xF000;

    if (byte == ACC_ANNOTATION_C) std::cout << "\t\tACC_ABSTRACT" << std::endl;
    if (byte == ACC_ENUM_C) std::cout << "\t\tACC_ABSTRACT" << std::endl;
}

void ClassFile::ShowThisClass() {
    std::cout << "This_class:\t\t" ;
    constant_pool->Reference(this_class-1);
    std::cout<<std::endl;
}

void ClassFile::ShowSuperClass() {
    std::cout << "Super_class:\t\t";
    constant_pool->Reference(super_class-1);
    std::cout<<std::endl;
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


void ClassFile::ShowConstantPool() {
    constant_pool->ShowConstantPoolTable();
}

void ClassFile::ShowFields() {

    std::cout<<"\n-----------\n";
    std::cout << "| Fields: |" << std::endl;
    std::cout<<"-----------\n";

    if (fields_count) {
        
        
        FieldsInfo* field;

        u2 byte;
        u2 flags;
        u2 name_index;
        u2 descriptor_index;

        for (int i = 0; i < fields_count; i++) {
            field = fields_table->GetField(i);

            flags = field->GetAccessFlags();

            // byte = flags & 0x000F;

            std::cout << "{\n" << std::endl;

            // switch(byte){
            //     case ACC_PUBLIC_F:
            //         std::cout << "public ";
            //         break;
            //     case ACC_PROTECTED_F:
            //         std::cout << "protected ";
            //         break;
            //     case ACC_PRIVATE_F:
            //         std::cout << "private ";
            //         break;
            // }



            name_index = field->GetNameIndex();
            /**
            switch (descriptor_string[0]) {
                case ((int)"B"):
                    std:: 
            }**/
            std::cout << constant_pool->GetUtf8(name_index) << " ";
            
            descriptor_index = field->GetDescriptorIndex();
            std::cout <<"\nDescriptor: "<<constant_pool->GetUtf8(descriptor_index) << std::endl;
            

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

void ClassFile::ShowInterfaces(){
    std::cout<<"\n---------------\n";
    std::cout << "| Interfaces: |" <<std::endl;
    std::cout<<"---------------\n";
    if (interfaces_count){

    }
    
}

void ClassFile::ShowMethods() {
    std::cout<<"\n------------\n";
    std::cout << "| Methods: |" << std::endl;
    std::cout<<"------------\n";
    if (methods_count) {
        
        
        MethodsInfo* method;

        u2 byte;
        u2 flags;
        u2 descriptor_index;
        u2 name_index;

        for (int i = 0; i < methods_count; i++) {

            method = methods_table->GetMethod(i);

            flags = method->GetAccessFlags();

            // byte = flags & 0x000F;
            // std::cout << "i " << i << "method " << method << "flags " << flags << "byte " << byte ;
            // std::cout << "\n";

            // switch(byte){
            //     case ACC_PRIVATE_M:
            //         std::cout << "private ";
            //         break;
            //     case ACC_PROTECTED_M:
            //         std::cout << "protected ";
            //         break;
            //     case ACC_PUBLIC_M:
            //         std::cout << "public ";
            //         break;
            //     case ACC_PUBLIC_M + ACC_STATIC_M:
            //         std::cout <<"public static ";
            // }

            name_index = (method->GetNameIndex());
            if (name_index == 0){
                std::cout << "Name: " << constant_pool->GetUtf8(name_index) << std::endl;
            } else{
                std::cout << "Name: " << constant_pool->GetUtf8(name_index-1) << std::endl;
            }
            
            descriptor_index = method->GetDescriptorIndex();
            std::cout <<"Descriptor: "<<constant_pool->GetUtf8(descriptor_index-1) << std::endl;
            

            byte = flags & 0x000F;

            std::cout << "Access Flags:"<< " ";
            Printu2Hex(byte);

            switch(byte){
                case 0:
                    std::cout<< " []" <<std::endl;
                    break;
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
                case ACC_PUBLIC_M + ACC_STATIC_M:
                    std::cout << " ACC_PUBLIC, ACC_STATIC" <<std::endl;
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

            std::cout << "\n}" << std::endl;

        }
    } else {
        std::cout << "Methods: " << std::endl;
    }

}


