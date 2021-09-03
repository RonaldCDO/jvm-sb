#include "methods.h"


u2 Method_info::GetAccessFlags(){
    return access_flags;
}


u2 Method_info::GetNameIndex(){
    return name_index;
}


u2 Method_info::GetDescriptorCount(){
    return descriptor_index;
}


u2 Method_info::GetAttributesCount(){
    return attributes_count;
}


