#include "attributes.h"

void AttributesInfo::Show() {
    std::cout << "Metodo especifico nao definido" << std::endl;
}


ConstantValueAtt::ConstantValueAtt(u2 attribute_name_index, u4 attribute_length, u2 constantvalue_index){
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
    this->constantvalue_index = constantvalue_index;
}

GenericAtt::GenericAtt(u2 attribute_name_index, u4 attribute_length, u1 * att_info) {
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
    this->att_info = att_info;
}


CodeAtt::CodeAtt(u2 attribute_name_index, u4 attribute_length, u2 max_stack, u2 max_locals, u4 code_length){
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
    this->max_stack = max_stack;
    this->max_locals = max_locals;
    this->code_length = code_length;
}

void CodeAtt::SetExceptionTableLength(u2 length) {
    this->exception_table_length = length;
}

void CodeAtt::SetAttributesLength(u2 length) {
    this->attributes_length = length;
}

void CodeAtt::AppendException(ExceptionsTableAtt* eta) {
    this->exceptions_table.push_back(eta);
}

void CodeAtt::AppendAttribute(GenericAtt* ga) {
    this->attributes_table.push_back(ga);
}

void CodeAtt::Show() {
    std::cout << "attribute_name_index: " << attribute_name_index << std::endl;
    std::cout << "attributes_length: " << attributes_length << std::endl;
    std::cout << "max_stack: " << max_stack << std::endl;
    std::cout << "max_locals: " << max_locals << std::endl;
    for (int i = 0; i < code_length; i++) {
        std::cout << code.at(i) << std::endl;
    }

}

void LineNumberTableAtt::AppendNumber(LineNumberTable * lnt){
    this->line_number_table.push_back(lnt);
}


ExceptionsAtt::ExceptionsAtt(u2 attribute_name_index, u4 attribute_length, u2 number_of_exceptions){
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
    this->number_of_exceptions = number_of_exceptions;
}

ExceptionsTableAtt::ExceptionsTableAtt(u2 start_pc, u2 end_pc, u2 handler_pc, u2 catch_type){
    this->start_pc = start_pc;
    this->end_pc = end_pc;
    this->handler_pc = handler_pc;
    this->catch_type = catch_type;
}

SourceFileAtt::SourceFileAtt(u2 attribute_name_index, u4 attribute_length, u2 sourcefile_index){
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
    this->sourcefile_index = sourcefile_index;
}


LineNumberTableAtt::LineNumberTableAtt(u2 attribute_name_index, u4 attribute_length, u2 line_number_table_length){
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
    this->line_number_table_length = line_number_table_length;
}


LocalVariableTableAtt::LocalVariableTableAtt(u2 attribute_name_index, u4 attribute_length, u2 local_variable_table_length){
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
    this->local_variable_table_length = local_variable_table_length;
}


u2 AttributesInfo::GetAttributeNameIndex(){
    return attribute_name_index;
}


u4 AttributesInfo::GetAttributeLength(){
    return attribute_length;
}


void AttributesTable::AppendConstantValue(u2 attribute_name_index, u4 attribute_length, u2 constantvalue_index){
    at.push_back(new ConstantValueAtt(attribute_name_index, attribute_length, constantvalue_index));
}


void AttributesTable::AppendCode(u2 attribute_name_index, u4 attribute_length, u2 max_stack, u2 max_locals, u4 code_length){
    at.push_back(new CodeAtt(attribute_name_index, attribute_length, max_stack, max_locals, code_length));
}


void AttributesTable::AppendExceptions(u2 attribute_name_index, u4 attribute_length, u2 number_of_exceptions){
    at.push_back(new ExceptionsAtt(attribute_name_index, attribute_length, number_of_exceptions));
}


void AttributesTable::AppendSourceFile(u2 attribute_name_index, u4 attribute_length, u2 sourcefile_index){
    at.push_back(new SourceFileAtt(attribute_name_index, attribute_length, sourcefile_index));
}


void AttributesTable::AppendLineNumberTable(u2 attribute_name_index, u4 attribute_length, u2 line_number_table_length){
    at.push_back(new LineNumberTableAtt(attribute_name_index, attribute_length, line_number_table_length));
}


void AttributesTable::AppendLocalVariableTableAtt(u2 attribute_name_index, u4 attribute_length, u2 local_variable_table_length){
    at.push_back(new LocalVariableTableAtt(attribute_name_index, attribute_length, local_variable_table_length));
}


