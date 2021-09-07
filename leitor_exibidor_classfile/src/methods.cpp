#include "methods.h"


MethodsInfo::MethodsInfo(u2 access_flags, u2 name_index, u2 descriptor_index, u2 attributes_count){
    this->access_flags = access_flags;
    this->name_index = name_index;
    this->descriptor_index = descriptor_index;
    this->attributes_count = attributes_count;

    // std::cout <<"acc_fl "<<access_flags << " name_idx "<< name_index << " dscp_idx " << descriptor_index <<" att_cnt "<<attributes_count <<std::endl;
}


u2 MethodsInfo::GetAccessFlags_M(){
    return access_flags;
}


u2 MethodsInfo::GetNameIndex_M(){
    return name_index - 1;
}


u2 MethodsInfo::GetDescriptorIndex_M(){
    return descriptor_index -1;
}


u2 MethodsInfo::GetAttributesCount_M(){
    return attributes_count;
}

void MethodsInfo::SetAttributesTable(AttributesTable* at){
    this->at = at;
}

void Methods::AppendMethod(MethodsInfo * MethodsInfo){
    methods.push_back(MethodsInfo);
}

MethodsInfo* Methods::GetMethod(int index){
   return methods.at(index); 
}
