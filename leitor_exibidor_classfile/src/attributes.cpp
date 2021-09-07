#include "attributes.h"

void AttributesInfo::Show() {
    std::cout << "Metodo especifico nao definido" << std::endl;
}


ConstantValueAtt::ConstantValueAtt(u2 attribute_name_index, u4 attribute_length, u2 constantvalue_index){
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
    this->constantvalue_index = constantvalue_index;
}


void ConstantValueAtt::Show(){
    std::cout << "attribute_name_index: " << attribute_name_index << std::endl;
    std::cout << "attributes_length: " << attribute_length   << std::endl;
    std::cout << "constant_value_index: " << constantvalue_index << std::endl;
}


GenericAtt::GenericAtt(u2 attribute_name_index, u4 attribute_length, u1 * att_info) {
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
    this->att_info = att_info;
}


CodeAtt::CodeAtt(u2 attribute_name_index, u4 attribute_length, u2 max_stack, u2 max_locals, u4 code_length, u1* code){
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
    this->max_stack = max_stack;
    this->max_locals = max_locals;
    this->code_length = code_length;
    this->code = code;
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
    std::cout << "attributes_length: " << attribute_length << std::endl;
    std::cout << "max_stack: " << max_stack << std::endl;
    std::cout << "max_locals: " << max_locals << std::endl;
    std::cout << "code_length: " << code_length << std::endl;
    std::cout << "teste" << attributes_table[0] << std::endl;

}

// void AttributesTable::ShowAttributesTable(){
//     CodeAtt * ct;
//     ct->Show();
// }


ExceptionsIndexTable::ExceptionsIndexTable(u1 indexes){
    this->indexes = indexes;
}

ExceptionsAtt::ExceptionsAtt(u2 attribute_name_index, u4 attribute_length){
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
}

void ExceptionsAtt::SetExceptionsIndexTableSize(u2 length){
    this->number_of_exceptions = length;
}

void ExceptionsAtt::AppendExceptionIndex(ExceptionsIndexTable* eit){
    this->exception_index_table.push_back(eit);
}

void ExceptionsAtt::Show() {
    std::cout << "attribute_name_index: " << attribute_name_index << std::endl;
    std::cout << "attributes_length: " << attribute_length << std::endl;
    std::cout << "number_of_exceptions: " << number_of_exceptions << std::endl;

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

void SourceFileAtt::Show(){
    // std::cout << "attribute_name_index: " << attribute_name_index << std::endl;
    // std::cout << "attributes_length: " << attribute_length << std::endl;
    // std::cout << "sourcefile_index: " << sourcefile_index << std::endl;

}


LineNumberTableAtt::LineNumberTableAtt(u2 attribute_name_index, u4 attribute_length){
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
}


LineNumberTable::LineNumberTable(u2 start_pc, u2 line_number){
    this->start_pc = start_pc;
    this->line_number = line_number;
}


void LineNumberTableAtt::SetLineNumberTableLength(u2 length){
    this->line_number_table_length = length;
}


void LineNumberTableAtt::AppendNumber(LineNumberTable * lnt){
    this->line_number_table.push_back(lnt);
}


void LineNumberTableAtt::Show(){
    std::cout << "attribute_name_index: " << attribute_name_index << std::endl;
    std::cout << "attributes_length: " << attribute_length << std::endl;
    std::cout << "line_number_table_length: " << line_number_table_length << std::endl;
}


LocalVariableTable::LocalVariableTable(u2 start_pc, u2 name_index, u2 descriptor_index, u2 index){
    this-> start_pc = start_pc;
    this-> name_index = name_index;
    this-> descriptor_index = descriptor_index;
    this-> index = index;
}


LocalVariableTableAtt::LocalVariableTableAtt(u2 attribute_name_index, u4 attribute_length){
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
}

void LocalVariableTableAtt::SetLocalVariableTableLength(u2 length){
    this->attribute_length = length;
}

void LocalVariableTableAtt::AppendVariable(LocalVariableTable * lvt){
    this->local_variable_table.push_back(lvt);
}


void LocalVariableTableAtt::Show(){
    std::cout << "attribute_name_index: " << attribute_name_index << std::endl;
    std::cout << "attributes_length: " << attribute_length << std::endl;
    std::cout << "local_variable_table_length: " << local_variable_table_length << std::endl;
}

u2 AttributesInfo::GetAttributeNameIndex(){
    return attribute_name_index;
}


u4 AttributesInfo::GetAttributeLength(){
    return attribute_length;
}


void AttributesTable::AppendConstantValue(u2 attribute_name_index, u4 attribute_length, u2 constantvalue_index){
    at.push_back(new ConstantValueAtt(attribute_name_index, attribute_length, constantvalue_index));
    std::cout << "attribute_name_index------>" << attribute_name_index <<std::endl;
    std::cout << "attribute_length------>" << attribute_length <<std::endl;
    std::cout << "constantvalue_index------>" << constantvalue_index <<std::endl;
}


void AttributesTable::AppendCode(u2 attribute_name_index, u4 attribute_length, u2 max_stack, u2 max_locals, u4 code_length, u1 * code){
    at.push_back(new CodeAtt(attribute_name_index, attribute_length, max_stack, max_locals, code_length, code));
}


void AttributesTable::AppendExceptions(u2 attribute_name_index, u4 attribute_length){
    at.push_back(new ExceptionsAtt(attribute_name_index, attribute_length));
}


void AttributesTable::AppendSourceFile(u2 attribute_name_index, u4 attribute_length, u2 sourcefile_index){
    at.push_back(new SourceFileAtt(attribute_name_index, attribute_length, sourcefile_index));
    std::cout<<"attribute_name_index ------->" << attribute_name_index << std::endl;
    std::cout<<"attribute_length ------->" << attribute_length << std::endl;
    std::cout<<"sourcefile_index -------> " << sourcefile_index << std::endl;
}


void AttributesTable::AppendLineNumberTable(u2 attribute_name_index, u4 attribute_length){
    at.push_back(new LineNumberTableAtt(attribute_name_index, attribute_length));
}


void AttributesTable::AppendLocalVariableTableAtt(u2 attribute_name_index, u4 attribute_length){
    at.push_back(new LocalVariableTableAtt(attribute_name_index, attribute_length));
}

void AttributesTable::AppendGeneric(u2 attribute_name_index, u4 attribute_length, u1 * info) {
    at.push_back(new GenericAtt(attribute_name_index, attribute_length, info));
    // std::cout<<"attribute_name_index: " <<attribute_name_index<<std::endl;
    // std::cout<<"attribute_length: " <<attribute_length<<std::endl;
    // std::cout<<"info: " <<info<<std::endl;
}


void AttributesTable::LoadAttributesTable(FILE* file, int attributes_count, ConstantPool* constant_pool) {

    u2 attribute_name_index;
    u4 attribute_length;
    u2 aux;
    u2 aux2;
    u1* att_info;
    u1* attribute_name;

    // std::cout<<"file: " << &file << "\n";
    //std::cout<<"attributes_count: " << attributes_count << "\n";
    // std::cout<<"constant_pool: " << &constant_pool << "\n";
    

        for (int i = 0; i < attributes_count; i++){

            attribute_name_index = Readu2(file);
            // std::cout<< "attribute_name_index: " << attribute_name_index<< std::endl;
            aux = Readu2(file);
            aux2 = Readu2(file);
            attribute_length = aux + aux2;
            // std::cout<< "attribute_length: " <<attribute_length << std::endl;
            
            attribute_name =  constant_pool->GetUtf8(attribute_name_index-1);
            
            std::cout << "attribute_name: " <<attribute_name << std::endl;

            att_info = Readu1(file, attribute_length);

            

            
           
            // if (strcmp((const char*)attribute_name, "ConstantValue") == 0) {
            //     u2 constantvalue_index = Readu2(file);
            //     AppendConstantValue(attribute_name_index, attribute_length, constantvalue_index);
            // }
            if (strcmp((const char*)attribute_name, "SourceFile") == 0) {
                u2 constantvalue_index = Readu2(file);
                AppendSourceFile(attribute_name_index, attribute_length, constantvalue_index);
             } //else if (strcmp((const char*)attribute_name, "Code") == 0) {
            //     u2 max_stack = Readu2(file);
            //     u2 max_locals = Readu2(file);
            //     aux = Readu2(file);
            //     aux2 = Readu2(file);
            //     u4 code_length = aux + aux2;
    
            //     std::cout <<"code_length ------> " << code_length << std::endl;
            //     u1* code = Readu1(file, code_length);

            //     CodeAtt* code_att = new CodeAtt(attribute_name_index, attribute_length, max_stack, max_locals, code_length, code);
                
            //     std::cout<<"__Problem here__" << std::endl;
            //     u2 exception_table_length = Readu2(file);
            //     std::cout<< "exception_table_length ------> " << exception_table_length <<std::endl;
            //     code_att->SetExceptionTableLength(exception_table_length);

            //     for (int i = 0; i < exception_table_length; i++) {
            //         code_att->AppendException(new ExceptionsTableAtt(Readu2(file), Readu2(file), Readu2(file), Readu2(file)));
            //     }
                
            //     u2 code_attributes_count = Readu2(file);
            //     for (int i = 0; i < code_attributes_count; i++) {
            //         u2 code_attribute_name_index = Readu2(file);
            //         u4 code_attribute_length = Readu4Raw(file);
            //         att_info = Readu1(file, attribute_length);
            //         code_att->AppendAttribute(new GenericAtt(code_attribute_name_index, code_attribute_length, att_info));                    
            //     }                
            //     // code_att->Show();
            // } 
            else{
                AppendGeneric(attribute_name_index, attribute_length, att_info);
            }

            /**

            else if (strcmp((const char*)attribute_name, "Exceptions") == 0) {
                ExceptionsAtt * exp_att = new ExceptionsAtt(Readu2(file), Readu4Raw(file));
                u2 number_of_exceptions = Readu2(file);

                exp_att->SetExceptionsIndexTableSize(number_of_exceptions);

                for(int i = 0; i< number_of_exceptions; i++){
                    exp_att->AppendExceptionIndex(new ExceptionsIndexTable(Readu1(file)));
                }
                
            }
            
            
            else if (strcmp((const char*)attribute_name, "SourceFile") == 0) {
                u2 constantvalue_index = Readu2(file);
                AppendSourceFile(attribute_name_index, attribute_length, constantvalue_index);
            } 

            else if (strcmp((const char*)attribute_name, "LineNumber") == 0) {
               LineNumberTableAtt * line_att = new LineNumberTableAtt(attribute_name_index, attribute_length);
               u2 line_number_table_length = Readu2(file);
               line_att->SetLineNumberTableLength(line_number_table_length);

                for (int i = 0; i < line_number_table_length; i++) {
                    line_att->AppendNumber(new LineNumberTable(Readu2(file), Readu2(file)));
                }
            }

            else if (strcmp((const char*)attribute_name, "LocalVariable") == 0) {
                LocalVariableTableAtt * local_att = new LocalVariableTableAtt(Readu2(file), Readu2(file));
                u2 local_variable_table_length = Readu2(file);

                local_att->SetLocalVariableTableLength(local_variable_table_length);
            
                for (int i = 0; i < local_variable_table_length; i++) {
                    local_att->AppendVariable(new LocalVariableTable(Readu2(file), Readu2(file),Readu2(file), Readu2(file)));
                }
            }

            else {
                std::cout << "generic" << std::endl;
                att_info = Readu1(file, attribute_length);
                AppendGeneric(attribute_name_index, attribute_length, att_info);

            }
            **/
            
            
        }
        

    
};