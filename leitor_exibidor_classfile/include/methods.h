#ifndef METHODS
#define METHODS

#include "data_class_format.h"
#include "attributes.h"


#define ACC_PUBLIC "0X0001"
#define ACC_PRIVATE "0X0002"
#define ACC_PROTECTED "0X0004"
#define ACC_STATIC "0X0008"
#define ACC_FINAL "0X0010"
#define ACC_SYNCRONIZED "0X0020"
#define ACC_BRIDGE "0X0040"
#define ACC_VARARGS "0X0080"
#define ACC_NATIVE "0X0100"
#define ACC_ABSTRACT "0X0400"
#define ACC_STRICT "0X0800"
#define ACC_SYNTHETIC "0X1000"


class Method_info{
    protected:
        u2 access_flags;
        u2 name_index;
        u2 descriptor_index;
        u2 attributes_count;
        Atributtes_info attributes;
    public:
        u2 GetAccessFlags();
        u2 GetNameIndex();
        u2 GetDescriptorCount();
        u2 GetAttributesCount();
};

// class Method_table{
//     protected:
//         std::vector<Method_info *> mt;
//     public:
//         void AppendMethod();
// };


#endif
