#ifndef METHODS
#define METHODS

#include "data_class_format.h"
#include "attributes.h"
#include <iostream>


#define ACC_PUBLIC_M 0X0001
#define ACC_PRIVATE_M 0X0002
#define ACC_PROTECTED_M 0X0004
#define ACC_STATIC_M 0X0008
#define ACC_FINAL_M 0X0010
#define ACC_SYNCRONIZED_M 0X0020
#define ACC_BRIDGE_M 0X0040
#define ACC_VARARGS_M 0X0080
#define ACC_NATIVE_M 0X0100
#define ACC_ABSTRACT_M 0X0400
#define ACC_STRICT_M 0X0800
#define ACC_SYNTHETIC_M 0X1000


class Methods_info{
    protected:
        u2 access_flags;
        u2 name_index;
        u2 descriptor_index;
        u2 attributes_count;
        std::vector<AttributesInfo*> attributes;
    public:
        Methods_info(u2 access_flags, u2 name_index, u2 descriptor_index, u2 attributes_count);
        u2 GetAccessFlags_M();
        u2 GetNameIndex_M();
        u2 GetDescriptorIndex_M();
        u2 GetAttributesCount_M();
};

class Methods{
    protected:
        std::vector<Methods_info *> methods;
    public:
        void AppendMethod(Methods_info * method_info);
        Methods_info* GetMethod(int index);
};


#endif
