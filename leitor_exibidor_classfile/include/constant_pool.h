#ifndef CP
#define CP

#include "data_class_format.h"

#define CLASS 7
#define FIELD_REF 9
#define METHOD_REF 10
#define INTERFACE_METHOD_RED 11
#define STRING 8
#define INTEGER 3
#define FLOAT 4
#define LONG 5  
#define DOUBLE 6
#define NAME_AND_TYPE 12
#define UTF8 1
#define METHOD_HANDLE 15
#define METHOD_TYPE 16
#define INVOKE_DYNAMIC 18



typedef struct{
    u1 tag; 
    std::vector<u1> info;
}cp_info;


typedef struct{
    u1 tag; 
    u2 name_Index;
}Class_info;


typedef struct{
    u1 tag; 
    u2 name_Index;
    u2 name_and_type_index;
}FieldRef_info;


typedef struct{
    u1 tag; 
    u2 name_Index;
    u2 name_and_type_index;
}MethodRef_info;


typedef struct{
    u1 tag ; 
    u2 name_Index;
}InterfaceMethodRef_info;


typedef struct{
    u1 tag; 
    u2 name_Index;
}String_info;


typedef struct{
    u1 tag; 
    u4 bytes;
}Integer_info;


typedef struct{
    u1 tag; 
    u4 bytes;
}Float_info;


typedef struct{
    u1 tag; 
    u4 high_bytes;
    u4 low_bytes;
}Long_info;


typedef struct{
    u1 tag; 
    u4 high_bytes;
    u4 low_bytes;
}Double_info;


typedef struct{
    u1 tag; 
    u2 name_Index;
    u2 descriptor_index;
}NameAndType_info;


typedef struct{
    u1 tag; 
    u2 length;
    std::vector<u1> bytes;
}UTF8_info;


typedef struct{
    u1 tag; 
    u2 reference_kind;
    u2 reference_index;
}MethodHandle_info;

typedef struct{
    u1 tag; 
    u2 descriptor_index;
}MethodType_info;


typedef struct{
    u1 tag; 
    u2 bootstrap_method_attr_index;
    u2 name_and_type_index;
}InvokeDynamic_info;


const std::string constant_type[] = {"Class", "Methodref", "Methodref", "InterfaceMethodRef",
                                 "String", "Integer", "Float", "Long", "Double", "NameAndType",
                                 "UTF8", "MethodHandle", "MethodType",
                                 "InvokeDynamic"};


#endif