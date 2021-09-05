#include "attributes.h"


ConstantValueAtt::ConstantValueAtt(u2 attribute_name_index, u4 attribute_length, u2 constantvalue_index){
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
    this->constantvalue_index = constantvalue_index;
}


CodeAtt::CodeAtt(u2 attribute_name_index, u4 attribute_length, u2 max_stack, u2 max_locals, u4 code_length){
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
    this->max_stack = max_stack;
    this->max_locals = max_locals;
    this->code_length = code_length;
}


ExceptionsAtt::ExceptionsAtt(u2 attribute_name_index, u4 attribute_length, u2 number_of_exceptions){
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
    this->number_of_exceptions = number_of_exceptions;
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


u2 Attributes_info::GetAttributeNameIndex(){
    return attribute_name_index;
}


u4 Attributes_info::GetAttributeLength(){
    return attribute_length;
}


void Attributes_table::AppendConstantValue(u2 attribute_name_index, u4 attribute_length, u2 constantvalue_index){
    at.push_back(new ConstantValueAtt(attribute_name_index, attribute_length, constantvalue_index));
}


void Attributes_table::AppendCode(u2 attribute_name_index, u4 attribute_length, u2 max_stack, u2 max_locals, u4 code_length){
    at.push_back(new CodeAtt(attribute_name_index, attribute_length, max_stack, max_locals, code_length));
}


void Attributes_table::AppendExceptions(u2 attribute_name_index, u4 attribute_length, u2 number_of_exceptions){
    at.push_back(new ExceptionsAtt(attribute_name_index, attribute_length, number_of_exceptions));
}


void Attributes_table::AppendSourceFile(u2 attribute_name_index, u4 attribute_length, u2 sourcefile_index){
    at.push_back(new SourceFileAtt(attribute_name_index, attribute_length, sourcefile_index));
}


void Attributes_table::AppendLineNumberTable(u2 attribute_name_index, u4 attribute_length, u2 line_number_table_length){
    at.push_back(new LineNumberTableAtt(attribute_name_index, attribute_length, line_number_table_length));
}


void Attributes_table::AppendLocalVariableTableAtt(u2 attribute_name_index, u4 attribute_length, u2 local_variable_table_length){
    at.push_back(new LocalVariableTableAtt(attribute_name_index, attribute_length, local_variable_table_length));
}


