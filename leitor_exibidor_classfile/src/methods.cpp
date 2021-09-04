#include "methods.h"


Methods_info::Methods_info(u2 access_flags, u2 name_index, u2 descriptor_index, u2 attributes_count){
    this->access_flags = access_flags;
    this->name_index = name_index;
    this->descriptor_index = descriptor_index;
    this->attributes_count = attributes_count;

    // std::cout <<" "<<access_flags << " "<< name_index << " " << descriptor_index <<" "<<attributes_count <<std::endl;
}


u2 Methods_info::GetAccessFlags(){
    return access_flags;
}


u2 Methods_info::GetNameIndex(){
    return name_index;
}


u2 Methods_info::GetDescriptorCount(){
    return descriptor_index;
}


u2 Methods_info::GetAttributesCount(){
    return attributes_count;
}


void Methods::AppendMethod(Methods_info * methods_info){
    methods.push_back(methods_info);
}
