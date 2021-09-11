#include "constant_pool.h"
#include <bitset>

// Funcao para pegar referencias das constantpools
void ConstantPool::Reference (u2 index) {
    u1 tag;
    tag = cp.at(index)->GetTag();
    if (tag == UTF8) {
        std::cout<< GetUtf8(index) << ":";
    }
    else{   // Pegar parametros para os metodos e chamar recursiva
        u2 arg2;
        u2 arg1 = cp.at(index)->GetArgs(&arg2);
        if (arg1 != 0) {
            Reference(arg1-1);
            if (arg2 != 0) {
                std::cout<<"";
                Reference(arg2-1);
            }
        }
    }
}

u1* ConstantPoolInfo::GetUtf8Bytes() {
    return NULL;
}


InfoClass::InfoClass(u1 tag, u2 name_index) {
    this->tag = tag;
    this->name_index = name_index;
}

void InfoClass::Show() {
    std::cout <<  "Class\t\t" << "#" << name_index<< "\t\t";

}

u2 InfoClass::GetArgs(u2 *arg2){
    *arg2 = 0;
    return name_index;
}

InfoFieldRef::InfoFieldRef(u1 tag, u2 class_index, u2 name_and_type_index) {
    this->tag = tag;
    this->class_index = class_index;
    this->name_and_type_index = name_and_type_index; 
}

void InfoFieldRef::Show() {
    std::cout << "Fieldref\t\t" << "#" << name_and_type_index << ".#" << class_index << "\t\t";
}

u2 InfoFieldRef::GetArgs(u2 *arg2){
    *arg2 = class_index;
    return name_and_type_index;
}

InfoMethodRef::InfoMethodRef(u1 tag, u2 class_index, u2 name_and_type_index) {
    this->tag = tag;
    this->class_index = class_index;
    this->name_and_type_index = name_and_type_index; 
}

void InfoMethodRef::Show() {
    std::cout<< "Methodref\t\t" << "#" << name_and_type_index << ".#" << class_index 
             << "\t\t";
}

u2 InfoMethodRef::GetArgs(u2 *arg2){
    *arg2 = class_index;
    return name_and_type_index;
}

InfoInterfaceMethodRef::InfoInterfaceMethodRef(u1 tag, u2 class_index, u2 name_and_type_index) {
    this->tag = tag;
    this->class_index = class_index;
    this->name_and_type_index = name_and_type_index; 
}

void InfoInterfaceMethodRef::Show() {
    std::cout<< "InterfaceMethodRef\t" << "#" << name_and_type_index << ".#" << class_index 
             << "\t\t";
}

u2 InfoInterfaceMethodRef::GetArgs(u2 *arg2){
    *arg2 = class_index;
    return name_and_type_index;
}

InfoString::InfoString(u1 tag, u2 string_index){
    this->tag = tag;
    this->string_index = string_index;
}
 
void InfoString::Show() {
    std::cout<<"String\t\t" << "#" << string_index << "\t\t";
}

u2 InfoString::GetArgs(u2 *arg2){
    *arg2 = 0;
    return string_index;
}

InfoInteger::InfoInteger(u1 tag, u4 bytes) {
    this->tag = tag;
    this->bytes = bytes;
}

void InfoInteger::Show() {
    std::cout<< "Integer\t\t" << bytes << "\t\t";
}

u2 InfoInteger::GetArgs(u2 *arg2){
    *arg2 = 0;
    return bytes;
}

InfoFloat::InfoFloat(u1 tag, u4 bytes) {
    this->tag = tag;
    this->bytes = bytes;
}


void InfoFloat::Show() {
    ulf u;
    std::stringstream stream;
    stream << std::hex << bytes;
    std::string result(stream.str());
    
    std::stringstream ss(result);
    ss >> std::hex >> u.ul;
    float f = u.f;
    
    std::cout<< "Float\t\t" << f <<"f" << "\t\t";
}

u2 InfoFloat::GetArgs(u2 *arg2){
    *arg2 = 0;
    return bytes;
}

InfoLong::InfoLong(u1 tag, u4 low_bytes, u4 high_bytes) {
    this->tag = tag;
    this->low_bytes = low_bytes;
    this->high_bytes = high_bytes;
}

void InfoLong::Show() {
    long datalong = (((long) high_bytes << 32) + low_bytes);
    // if (datalong < 0) {
    //     datalong = datalong +1;
    // }
    std::cout<< "Long\t\t" << datalong <<"d" << "\t\t";
}

u2 InfoLong::GetArgs(u2 *arg2){
    *arg2 = 0;
    return 0;
}

InfoDouble::InfoDouble(u1 tag, u4 low_bytes, u4 high_bytes) {
    this->tag = tag;
    this->low_bytes = low_bytes;
    this->high_bytes = high_bytes;
}

// union Converter { uint32_t i; double d; };


void InfoDouble::Show() {

    double datadouble;
    long bits = (((long) high_bytes << 32) + low_bytes);

    int s = ((bits >> 63) == 0) ? 1 : -1;
    int e = ((bits >> 52) & 0x7ffL);
	long m = (e == 0) ? (bits & 0xfffffffffffffL) << 1 : (bits & 0xfffffffffffffL) | 0x10000000000000L;
		
	datadouble = (s * m * pow(2, (e-1075)));

    std::cout<< "Double\t\t"<< datadouble <<"d" << "\t\t";
}

u2 InfoDouble::GetArgs(u2 *arg2){
    *arg2 = 0;
    return 0;
}

void InfoLongDoubleDummy::Show() {}

u2 InfoLongDoubleDummy::GetArgs(u2 *arg2){
    *arg2 = 0;
    return 0;
}

InfoNameAndType::InfoNameAndType(u1 tag, u2 name_index, u2 descriptor_index) {
    this->tag = tag;
    this->name_index = name_index;
    this->descriptor_index = descriptor_index;
}

void InfoNameAndType::Show() {
    std::cout<< "NameAndType\t" << "#" << descriptor_index << ".#" << name_index << "\t\t";
}

u2 InfoNameAndType::GetArgs(u2 *arg2){
    *arg2 = name_index;
    return descriptor_index;
}

InfoUtf8::InfoUtf8(u1 tag, u2 length, u1 * bytes) {
    this->tag = tag;
    this->length = length;
    this->bytes = bytes;
}

void InfoUtf8::Show() {
    std::cout << "Utf8\t\t" << bytes<< "\t";
}

u2 InfoUtf8::GetArgs(u2 *arg2){
    *arg2 = 0;
    return 0;
}

u1 * InfoUtf8::GetUtf8Bytes() {
    return bytes;
}

InfoMethodHandle::InfoMethodHandle(u1 tag, u1 reference_kind, u2 reference_index) {
    this->tag = tag;
    this->reference_kind = reference_kind;
    this->reference_index = reference_index;
}

void InfoMethodHandle::Show() {
    std::cout<<"InfoMethodHandle" << "#" << reference_index <<".#" << reference_kind << "\t\t";
}

u2 InfoMethodHandle::GetArgs(u2 *arg2){
    *arg2 = reference_kind;
    return reference_index;
}

InfoMethodType::InfoMethodType(u1 tag, u2 descriptor_index) {
    this->tag = tag;
    this->descriptor_index = descriptor_index;
}

void InfoMethodType::Show() {
    std::cout<<"InfoMethodType\t" << "#" << descriptor_index << "\t\t";
}

u2 InfoMethodType::GetArgs(u2 *arg2){
    *arg2 = 0;
    return descriptor_index;
}

InfoInvokeDynamic::InfoInvokeDynamic(u1 tag, u2 bootstrap_method_attr_index, u2 name_and_type_index) {
    this->tag = tag;
    this->bootstrap_method_attr_index = bootstrap_method_attr_index;
    this->name_and_type_index = name_and_type_index;
}

void InfoInvokeDynamic::Show() {
    std::cout<<"InvokeDynamic\t" << "#" << name_and_type_index << ":#" << bootstrap_method_attr_index 
             << std::endl;
}

u2 InfoInvokeDynamic::GetArgs(u2 *arg2){
    *arg2 = bootstrap_method_attr_index;
    return name_and_type_index;
}


u1 ConstantPoolInfo::GetTag() {
    return tag;
}

void ConstantPool::AppendClass(u1 tag, u2 name_index) {
    cp.push_back(new InfoClass(tag, name_index));
}

void ConstantPool::AppendFieldRef(u1 tag, u2 class_index, u2 name_and_type_index) {
    cp.push_back(new InfoFieldRef(tag, class_index, name_and_type_index));
}

void ConstantPool::AppendMethodRef(u1 tag, u2 class_index, u2 name_and_type_index) {
    cp.push_back(new InfoMethodRef(tag, class_index, name_and_type_index));
}

void ConstantPool::AppendInterfaceMethodRef(u1 tag, u2 class_index, u2 name_and_type_index) {
    cp.push_back(new InfoInterfaceMethodRef(tag, class_index, name_and_type_index));
}

void ConstantPool::AppendString(u1 tag, u2 string_index) {
    cp.push_back(new InfoString(tag, string_index));
}

void ConstantPool::AppendInt(u1 tag, u4 bytes) {
    cp.push_back(new InfoInteger(tag, bytes));
}

void ConstantPool::AppendFloat(u1 tag, u4 bytes) {
    cp.push_back(new InfoFloat(tag, bytes));
}

void ConstantPool::AppendLong(u1 tag, u4 high_bytes, u4 low_bytes) {
    cp.push_back(new InfoLong(tag, high_bytes, low_bytes));
    cp.push_back(new InfoLongDoubleDummy());
}

void ConstantPool::AppendDouble(u1 tag, u4 high_bytes, u4 low_bytes) {
    cp.push_back(new InfoDouble(tag, high_bytes, low_bytes));
    cp.push_back(new InfoLongDoubleDummy());
}

void ConstantPool::AppendNameAndType(u1 tag, u2 name_index, u2 descriptor_index) {
    cp.push_back(new InfoNameAndType(tag, name_index, descriptor_index));
}

void ConstantPool::AppendUtf8(u1 tag, u2 length, u1 * bytes) {
    cp.push_back(new InfoUtf8(tag, length, bytes));
}

void ConstantPool::AppendMethodHandle(u1 tag, u1 reference_kind, u2 reference_index) {
    cp.push_back(new InfoMethodHandle(tag, reference_kind, reference_index));
}

void ConstantPool::AppendMethodType(u1 tag, u2 descriptor_index) {
    cp.push_back(new InfoMethodType(tag, descriptor_index));
}

void ConstantPool::AppendInvokeDynamic(u1 tag, u2 bootstrap_method_attr_index, u2 name_and_type_index) {
    cp.push_back(new InfoInvokeDynamic(tag, bootstrap_method_attr_index, name_and_type_index));
}

void ConstantPool::ShowConstantPoolTable() {
    std::cout<<"\n-----------------";
    std::cout<<"\n| Constant Pool |:"<<std::endl;
    std::cout<<"-----------------\n";
    int length = cp.size();
    u1 tag;
    for (int i = 0; i < length; i++) {
        std::cout<<"#"<< i+1 << " = ";

        tag = cp.at(i)->GetTag();
        if (tag != DOUBLE && tag != LONG && tag != FLOAT && tag != INTEGER) {
            if (tag != UTF8){
                cp.at(i)->Show();
                std::cout<< "|| ";
                Reference(i);
            } else {
                cp.at(i)->Show();
            }
        } else {
            cp.at(i)->Show();
        }
        if (tag == LONG || tag == DOUBLE) {
            i++;
        }

    
        std::cout<<std::endl;
    }
}

u1* ConstantPool::GetUtf8(int index) {
    return cp.at(index)->GetUtf8Bytes();
}