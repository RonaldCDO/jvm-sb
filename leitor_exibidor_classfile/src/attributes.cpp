#include "attributes.h"


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


