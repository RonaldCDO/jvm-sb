#include "fields.h"

Fields_info::Fields_info(u2 access_flags, u2 name_index, u2 descriptor_index, u2 attributes_count){
  this->access_flags = access_flags;
  this->name_index = name_index;
  this-> descriptor_index = descriptor_index;
  this-> attributes_count = attributes_count;
}

u2 Fields_info::GetAccessFlags(){
  return access_flags; 
}


u2 Fields_info::GetNameIndex(){
  return name_index; 
}


u2 Fields_info::GetDescriptorIndex(){
  return descriptor_index; 
}


u2 Fields_info::GetAttributesCount(){
  return attributes_count; 
}


