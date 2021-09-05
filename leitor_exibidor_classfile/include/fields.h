#ifndef FIELDS
#define FIELDS

#include "data_class_format.h"
#include "attributes.h"
#include <iostream>

#define ACC_PUBLIC_F 0x0001
#define ACC_PRIVATE_F 0x0002
#define ACC_PROTECTED_F 0x0004
#define ACC_STATIC_F 0x0008
#define ACC_FINAL_F 0x0010
#define ACC_VOLATILE_F 0x0040
#define ACC_TRANSIENT_F 0x0080
#define ACC_SYNTHETIC_F 0x1000
#define ACC_ENUM_F 0x4000

class FieldsInfo {
    protected:
        u2 access_flags;
        u2 name_index;
        u2 descriptor_index;
        u2 attributes_count;
        // char* descriptor;
        // char* name;
        AttributesTable* at;
    public:
        FieldsInfo(u2 access_flags, u2 name_index, u2 descriptor_index, u2 attributes_count);
        u2 GetAccessFlags();
        u2 GetNameIndex();
        u2 GetDescriptorIndex();
        u2 GetAttributesCount();
        // void SetDescriptor(char* descriptor);
        // void SetName(char* name);
        void SetAttributesTable(AttributesTable* at);
}; 

class Fields {
    protected:
        std::vector<FieldsInfo *> fields;
    public:
        void appendField(FieldsInfo * fields_info);
        FieldsInfo* GetField(int index);
};

#endif