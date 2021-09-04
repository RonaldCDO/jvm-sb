#ifndef FIELDS
#define FIELDS

#include "data_class_format.h"
#include "attributes.h"
#include <iostream>

#define ACC_PUBLIC "0x0001"
#define ACC_PRIVATE "0x0002"
#define ACC_PROTECTED "0x0004"
#define ACC_STATIC "0x0008"
#define ACC_FINAL "0x0010"
#define ACC_VOLATILE "0x0040"
#define ACC_TRANSIENT "0x0080"
#define ACC_SYNTHETIC "0x1000"
#define ACC_ENUM "0x4000"


class Fields_info {
    protected:
        u2 access_flags;
        u2 name_index;
        u2 descriptor_index;
        u2 attributes_count;
        std::vector<Attributes_info*> attributes;
    public:
        Fields_info(u2 access_flags, u2 name_index, u2 descriptor_index, u2 attributes_count);
        u2 GetAccessFlags();
        u2 GetNameIndex();
        u2 GetDescriptorIndex();
        u2 GetAttributesCount();
}; 


class Fields {
    protected:
        std::vector<Fields_info *> fields;
    public:
        void appendField(Fields_info * fields_info);
};
#endif