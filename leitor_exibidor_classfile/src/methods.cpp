#include "methods.h"


MethodsInfo::MethodsInfo(u2 access_flags, u2 name_index, u2 descriptor_index, u2 attributes_count){
    this->access_flags = access_flags;
    this->name_index = name_index;
    this->descriptor_index = descriptor_index;
    this->attributes_count = attributes_count;
}

void MethodsInfo::SetAttributesTable(AttributesTable* attributes){
    this->attributes = attributes;
}

void Methods::AppendMethod(MethodsInfo * MethodsInfo){
    methods.push_back(MethodsInfo);
}

MethodsInfo* Methods::GetMethod(int index){
   return methods.at(index); 
}

void MethodsInfo::printAttributesTable() {
    attributes->ShowAttributesTable();
}

void Methods::ShowMethods(int methods_count, ConstantPool* cp) {
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

            method = methods.at(i);

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
                std::cout << "Name: " << cp->GetUtf8(name_index) << std::endl;
            } else{
                std::cout << "Name: " << cp->GetUtf8(name_index-1) << std::endl;
            }
            
            descriptor_index = method->GetDescriptorIndex();
            std::cout << "Descriptor: "<< cp ->GetUtf8(descriptor_index-1) << std::endl;
            

            byte = flags & 0x000F;

            std::cout << "Access Flags:"<< " ";
            Printu2Hex(byte);

            switch(byte){
                case 0:
                    std::cout<< " []" <<std::endl;
                    break;
                case ACC_PUBLIC_M:
                    std::cout << "\tACC_PUBLIC" << std::endl;
                    break;
                case ACC_PROTECTED_M:
                    std::cout << "\tACC_PROTECTED" << std::endl;
                    break;
                case ACC_PRIVATE_M:
                    std::cout << "\tACC_PRIVATE" << std::endl;
                    break;
                case ACC_STATIC_M:
                    std::cout << "\tACC_STATIC" << std::endl;
                    break;
                case ACC_PUBLIC_M + ACC_STATIC_M:
                    std::cout << " ACC_PUBLIC, ACC_STATIC" <<std::endl;
            }

            byte = flags & 0x00F0;

            switch(byte){
                case ACC_FINAL_M:
                    std::cout << "\tACC_FINAL" << std::endl;
                    break;
                case ACC_SYNCRONIZED_M:
                    std::cout << "\tACC_SYNCRONIZED" << std::endl;
                    break;
                case ACC_BRIDGE_M:
                    std::cout << "\tACC_BRIDGE" << std::endl;
                    break;
                  case ACC_VARARGS_M:
                    std::cout << "\tACC_VARARGS" << std::endl;
                    break;
                    
            }

            byte = flags & 0x0F00;

                switch(byte){
                case ACC_NATIVE_M:
                    std::cout << "\tACC_NATIVE" << std::endl;
                    break;
                case ACC_ABSTRACT_M:
                    std::cout << "\tACC_ABSTRACT" << std::endl;
                    break;
                case ACC_STRICT_M:
                    std::cout << "\tACC_STRICT" << std::endl;
                    break;
                case ACC_SYNTHETIC_M:
                    std::cout << "\tACC_SYNTHETIC" << std::endl;
                    break;
            }

            method->printAttributesTable();

            std::cout << "\n}" << std::endl;

        }
    } else {
        std::cout << "Classe não possui Methods.\n\n" << std::endl;
    }
}