#include "constant_pool.h"
#include <bitset>

// Funcao para pegar referencias das constantpools
void ConstantPool::Reference (ConstantPoolInfo * cp) {
    u1 tag;
    tag = cp->GetTag();
    if (tag == UTF8) {
        cp->Show();
    }
    // else{   // Pegar parametros para os metodos e chamar recursiva
    //     // arg1 = cp->GetArg1(tag);
    //     // arg2 = cp->GetArg2(tag);
    //     // Referencia(arg1);
    //     // if (tag != CLASS || tag != STRING || tag != METHOD_TYPE) {
    //     //     Referencia(arg2);
    //     }
}

InfoClass::InfoClass(u1 tag, u2 name_index) {
    this->tag = tag;
    this->name_index = name_index;
    
}

void InfoClass::Show() {
    std::cout <<  "Class\t\t" << "#" << name_index <<std::endl;

}

InfoFieldRef::InfoFieldRef(u1 tag, u2 class_index, u2 name_and_type_index) {
    this->tag = tag;
    this->class_index = class_index;
    this->name_and_type_index = name_and_type_index; 
}

void InfoFieldRef::Show() {
    std::cout << "Fieldref\t\t" << "#" << name_and_type_index << ".#" << class_index << std::endl;
}

InfoMethodRef::InfoMethodRef(u1 tag, u2 class_index, u2 name_and_type_index) {
    this->tag = tag;
    this->class_index = class_index;
    this->name_and_type_index = name_and_type_index; 
}

void InfoMethodRef::Show() {
    std::cout<< "Methodref\t\t" << "#" << name_and_type_index << ".#" << class_index 
             << std::endl;
}

InfoInterfaceMethodRef::InfoInterfaceMethodRef(u1 tag, u2 class_index, u2 name_and_type_index) {
    this->tag = tag;
    this->class_index = class_index;
    this->name_and_type_index = name_and_type_index; 
}

void InfoInterfaceMethodRef::Show() {
    std::cout<< "InterfaceMethodRef\t" << "#" << name_and_type_index << ".#" << class_index 
             << std::endl;
}

InfoString::InfoString(u1 tag, u2 string_index){
    this->tag = tag;
    this->string_index = string_index;
}
 
void InfoString::Show() {
    std::cout<<"String\t\t" << "#" << string_index << std::endl;
}

InfoInteger::InfoInteger(u1 tag, u4 bytes) {
    this->tag = tag;
    this->bytes = bytes;
}

void InfoInteger::Show() {
    std::cout<< "Integer\t\t" << bytes <<std::endl;
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
    
    std::cout<< "Float\t\t" << f <<"f" <<  std::endl;
}

InfoLong::InfoLong(u1 tag, u4 high_bytes, u4 low_bytes) {
    this->tag = tag;
    this->high_bytes = high_bytes;
    this->low_bytes = low_bytes;
}

void InfoLong::Show() {
    std::cout<< "Long\t\t" << " ! " <<std::endl;
}

InfoDouble::InfoDouble(u1 tag, u4 high_bytes, u4 low_bytes) {
    this->tag = tag;
    this->high_bytes = high_bytes;
    this->low_bytes = low_bytes;
}

union Converter { uint32_t i; double d; };

// double convert(std::bitset<32> const& bs) {
//     Converter c;
//     c.i = bs.to_ullong();
//     return c.d;
// }

void InfoDouble::Show() {

    // std::bitset<32> teste (low_bytes);
    // std::bitset<32> teste2 (high_bytes);
    // std::vector<int> a;
    // for (int i= 0 ; i< teste2.size(); i++){
    //     a.push_back(teste[i]);
    // }
    // for (int i= 0 ; i< teste.size(); i++){
    //     a.push_back(teste2[i]);    
    // }
    // for (int c : a)
    //     std::cout<< c;
    //     std::cout<<std::endl;
    
    
    // std::cout<< teste <<std::endl;
    // std::cout<< "teste3: " <<teste3 <<std::endl;

    // std::stringstream stream;
    // stream << std::hex << high_bytes;
    // std::string result(stream.str());
    // std::stringstream ss(result);
    
    // std::cout<< result;


    std::cout<< "Double\t\t"<< " ! " <<std::endl;
}

void InfoLongDoubleDummy::Show() {}

InfoNameAndType::InfoNameAndType(u1 tag, u2 name_index, u2 descriptor_index) {
    this->tag = tag;
    this->name_index = name_index;
    this->descriptor_index = descriptor_index;
}

void InfoNameAndType::Show() {
    std::cout<< "NameAndType\t" << "#" << descriptor_index << ".#" << name_index << std::endl;
}

InfoUtf8::InfoUtf8(u1 tag, u2 length, u1 * bytes) {
    this->tag = tag;
    this->length = length;
    this->bytes = bytes;
}

void InfoUtf8::Show() {
    std::cout << "Utf8\t\t" << bytes <<std::endl;
}


InfoMethodHandle::InfoMethodHandle(u1 tag, u1 reference_kind, u2 reference_index) {
    this->tag = tag;
    this->reference_kind = reference_kind;
    this->reference_index = reference_index;
}

void InfoMethodHandle::Show() {
    std::cout<<"InfoMethodHandle" << "#" << reference_index <<".#" << reference_kind <<std::endl;
}

InfoMethodType::InfoMethodType(u1 tag, u2 descriptor_index) {
    this->tag = tag;
    this->descriptor_index = descriptor_index;
}

void InfoMethodType::Show() {
    std::cout<<"InfoMethodType\t" << "#" << descriptor_index <<std::endl;
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

// void ConstantPoolInfo::SetTag(u1 tag) {
//     this->tag = tag;
// }

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
    std::cout<<"Constant Pool:"<<std::endl;
    int length = cp.size();
    u1 tag;
    for (int i = 0; i < length; i++) {
        std::cout<<"#"<< i+1 << " = ";
        cp.at(i)->Show();
        tag = cp.at(i)->GetTag();
        if (tag != UTF8){
            Reference(cp.at(i));
        }
        if (tag == LONG || tag == DOUBLE) {
            i++;
        } 
    }
}