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
        void SetTag(u1 tag);
        u1 GetTag();
        void virtual Show() = 0;
};

class ConstantPool {
    protected:
        std::vector<ConstantPoolInfo*> cp;
    public:
        void AppendClass(u1 tag, u2 name_index);
        void AppendFieldRef(u1 tag, u2 class_index, u2 name_and_type_index);
        void AppendMethodRef(u1 tag, u2 class_index, u2 name_and_type_index);
        void AppendInterfaceMethodRef(u1 tag, u2 class_index, u2 name_and_type_index);
        void AppendString(u1 tag, u2 name_index);
        void AppendInt(u1 tag, u4 bytes);
        void AppendFloat(u1 tag, u4 bytes);
        void AppendLong(u1 tag, u4 high_bytes, u4 low_bytes);
        void AppendDouble(u1 tag, u4 high_bytes, u4 low_bytes);
        void AppendNameAndType(u1 tag, u2 name_index, u2 descriptor_index);
        void AppendUtf8(u1 tag, u2 length, u1 * bytes);
        void AppendMethodHandle(u1 tag, u1 reference_type, u2 reference_index);
        void AppendMethodType(u1 tag, u2 descriptor_index);
        void AppendInvokeDynamic(u1 tag, u2 bootstrap_method_attr_index, u2 name_and_type_index);
        void ShowConstantPoolTable(int length);
};


class InfoClass: public ConstantPoolInfo {
    protected: 
        u2 name_index;
    public:
        InfoClass(u1 tag, u2 name_index);
        void Show();
        u2 GetNameIndex(); 
};

class InfoFieldRef: public ConstantPoolInfo {
    protected:
        u2 class_index;
        u2 name_and_type_index;
    public:
        InfoFieldRef(u1 tag, u2 class_index, u2 name_and_type_index);
        void Show();
};

class InfoMethodRef: public ConstantPoolInfo {
    protected:
        u2 class_index;
        u2 name_and_type_index;
    public:
        InfoMethodRef(u1 tag, u2 class_index, u2 name_and_type_index);
        void Show();
};

class InfoInterfaceMethodRef: public ConstantPoolInfo {
    protected:
        u2 class_index;
        u2 name_and_type_index;
    public:
        InfoInterfaceMethodRef(u1 tag, u2 class_index, u2 name_and_type_index);
        void Show();
};

class InfoString: public ConstantPoolInfo {
    protected:
        u2 string_index;
    public:
        InfoString(u1 tag, u2 string_index);
        void Show();
};

class InfoInteger: public ConstantPoolInfo {
    protected:
        u4 bytes;
    public:
        InfoInteger(u1 tag, u4 bytes);
        void Show();
};

class InfoFloat: public ConstantPoolInfo {
    protected:
        u4 bytes;
    public:
        InfoFloat(u1 tag, u4 bytes);
        void Show();
};

class InfoLong: public ConstantPoolInfo {
    protected:
        u4 high_bytes;
        u4 low_bytes;
    public:
        InfoLong(u1 tag, u4 high_bytes, u4 low_bytes);
        void Show();
};

class InfoDouble: public ConstantPoolInfo {
    protected:
        u4 high_bytes;
        u4 low_bytes;
    public:
        InfoDouble(u1 tag, u4 high_bytes, u4 low_bytes);
        void Show();
};

class InfoNameAndType: public ConstantPoolInfo {
    protected:
        u2 name_index;
        u2 descriptor_index;
    public:
        InfoNameAndType(u1 tag, u2 name_index, u2 descriptor_index);
        void Show();
};

class InfoUtf8: public ConstantPoolInfo {
    protected:
        u2 length;
        u1 * bytes;
    public:
        InfoUtf8(u1 tag, u2 length, u1 * bytes);
        void Show();
};

class InfoMethodHandle: public ConstantPoolInfo {
    protected:
        u1 reference_kind;
        u2 reference_index;
    public:
        InfoMethodHandle(u1 tag, u1 reference_kind, u2 reference_index);
        void Show();
};

class InfoMethodType: public ConstantPoolInfo {
    protected:
        u2 descriptor_index;
    public:
        InfoMethodType(u1 tag, u2 descriptor_index);
        void Show();
};

class InfoInvokeDynamic: public ConstantPoolInfo {
    protected:
        u2 bootstrap_method_attr_index;
        u2 name_and_type_index;
    public:
        InfoInvokeDynamic(u1 tag, u2 bootstrap_method_attr_index, u2 name_and_type_index);
        void Show();
};



#endif