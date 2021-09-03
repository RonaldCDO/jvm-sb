#include "fields.h"


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


