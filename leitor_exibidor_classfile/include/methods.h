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


class MethodsInfo{
    protected:
        u2 access_flags;
        u2 name_index;
        u2 descriptor_index;
        u2 attributes_count;
        AttributesTable * attributes;
    public:
        MethodsInfo(u2 access_flags, u2 name_index, u2 descriptor_index, u2 attributes_count);
        inline u2 GetAccessFlags(){return access_flags;};
        inline u2 GetNameIndex(){return name_index;};
        inline u2 GetDescriptorIndex(){return descriptor_index;};
        inline u2 GetAttributesCount(){return attributes_count;};
        void SetAttributesTable(AttributesTable* at);
};

class Methods{
    protected:
        std::vector<MethodsInfo *> methods;
    public:
        void AppendMethod(MethodsInfo * method_info);
        MethodsInfo* GetMethod(int index);
};


#endif
