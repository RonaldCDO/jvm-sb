#include "constant_pool.h"

/**
void ConstantPool::CreateEntry(u1 incoming_tag) {

    std::cout << incoming_tag << std::endl;

    switch(incoming_tag) {
        case CLASS:
            std::cout << "Class_type" << std::endl;
            break;
        case FIELD_REF:
            std::cout << "FieldRef_type" << std::endl;
            break;
        case METHOD_REF:
            std::cout << "MethodRef_type" << std::endl;
            break;
        case INTERFACE_METHOD_REF:
            std::cout << "InterfaceMethodRef_type" << std::endl;
            break;
        case STRING:
            std::cout << "String_type" << std::endl;
            break;
        case INTEGER:
            std::cout << "Integer_type" << std::endl;
            break;
        case FLOAT:
            std::cout << "Float_type" << std::endl;
            break;
        case LONG:
            std::cout << "Long_type" << std::endl;
            break;
        case DOUBLE:
            std::cout << "Double_type" << std::endl;
            break;
        case NAME_AND_TYPE:
            std::cout << "NameAndType_type" << std::endl;
            break;
        case UTF8:
            std::cout << "Utf8_type" << std::endl;
            break;
        case METHOD_HANDLE:
            std::cout << "MethodHandle_type" << std::endl;
            break;
        case METHOD_TYPE:
            std::cout << "MethodType_type" << std::endl;
            break;
        case INVOKE_DYNAMIC:
            std::cout << "InvokeDynamic_type" << std::endl;
            break;
    }    
};

**/


void ConstantPoolInfo::SetData(u1 data){
    U1 = data;
};
void ConstantPoolInfo::SetData(u2 data){
    U2 = data;
};
void ConstantPoolInfo::SetData(u4 data){
    U4 = data;
};

void ConstantPool::Append(u1 data){
    ConstantPoolInfo * address = (ConstantPoolInfo*)malloc(sizeof(u1));
    address->SetData(data);
    cp.push_back(address);
};


void ConstantPool::Append(u2 data){
    ConstantPoolInfo * address = (ConstantPoolInfo*)malloc(sizeof(u2));
    address->SetData(data);
    cp.push_back(address);
};


void ConstantPool::Append(u4 data){
    ConstantPoolInfo * address = (ConstantPoolInfo*)malloc(sizeof(u4));
    address->SetData(data);
    cp.push_back(address);
};