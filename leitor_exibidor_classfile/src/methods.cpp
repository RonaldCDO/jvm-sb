#include "methods.h"


Methods_info::Methods_info(u2 access_flags, u2 name_index, u2 descriptor_index, u2 attributes_count){
    this->access_flags = access_flags;
    this->name_index = name_index;
    this->descriptor_index = descriptor_index;
    this->attributes_count = attributes_count;

    std::cout <<"acc_fl "<<access_flags << " name_idx "<< name_index << " dscp_idx " << descriptor_index <<" att_cnt "<<attributes_count <<std::endl;
}


u2 Methods_info::GetAccessFlags_M(){
    return access_flags;
}


u2 Methods_info::GetNameIndex_M(){
    return name_index -1;
}


u2 Methods_info::GetDescriptorIndex_M(){
    return descriptor_index -1;
}


u2 Methods_info::GetAttributesCount_M(){
    return attributes_count;
}


void Methods::AppendMethod(Methods_info * methods_info){
    methods.push_back(methods_info);
}

Methods_info* Methods::GetMethod(int index){
   return methods.at(index); 
}
