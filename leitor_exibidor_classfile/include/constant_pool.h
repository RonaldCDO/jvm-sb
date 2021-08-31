#include <iostream>
#include <vector>
#include <data_class_format.h>

#ifndef CP
#define CP

#define CLASS 7
#define FIELD_REF 9
#define METHOD_REF 10
#define INTERFACE_METHOD_REF 11
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

class ConstantPoolInfo {
    protected:
        u1 tag;
    public: 
        u1 GetTag();
        u1 SetTag();
};

class ConstantPool {
    protected:
        std::vector<ConstantPoolInfo> cp;
    public:
};

class InfoClass: public ConstantPoolInfo {
    protected: 
        u2 name_index;
};

class InfoFieldRef: public ConstantPoolInfo {
    protected:
        u2 class_index;
        u2 name_and_type_index;
};

class InfoMethodRef: public ConstantPoolInfo {
    protected:
        u2 class_index;
        u2 name_and_type_index;
};

class InfoInterfaceMethodRef: public ConstantPoolInfo {
    protected:
        u2 class_index;
        u2 name_and_type_index;
};

class InfoString: public ConstantPoolInfo {
    protected:
        u2 string_index;
};

class InfoInteger: public ConstantPoolInfo {
    protected:
        u4 bytes;
};

class InfoFloat: public ConstantPoolInfo {
    protected:
        u4 bytes;
};

class InfoLong: public ConstantPoolInfo {
    protected:
        u4 high_bytes;
        u4 low_bytes;
};

class InfoDouble: public ConstantPoolInfo {
    protected:
        u4 high_bytes;
        u4 low_bytes;
};

class InfoNameAndType: public ConstantPoolInfo {
    protected:
        u2 name_index;
        u4 descriptor_index;
};

class InfoUtf8: public ConstantPoolInfo {
    protected:
        u2 length;
        u1 bytes[];
};

class InfoMethodHandle: public ConstantPoolInfo {
    protected:
        u1 reference_kind;
        u2 reference_index;
};

class InfoMethodType: public ConstantPoolInfo {
    protected:
        u2 descriptor_index;
};

class InfoInvokeDynamic: public ConstantPoolInfo {
    protected:
        u2 bootstrap_method_attr_index;
        u2 name_and_type_index;
};



#endif