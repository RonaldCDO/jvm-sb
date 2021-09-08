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
