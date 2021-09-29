#include "attributes.h"

void AttributesInfo::Show() {
    std::cout << "Metodo especifico nao definido" << std::endl;
}

void AttributesTable::AppendAttribute(AttributesInfo * attribute) {
    at.push_back(attribute);
}


ConstantValueAtt::ConstantValueAtt(u2 attribute_name_index, u4 attribute_length, u2 constantvalue_index){
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
    this->constantvalue_index = constantvalue_index;
}


void ConstantValueAtt::Show(){
    std::cout << "\t>>> Constant Value: " << std::endl;
    std::cout << "\tattribute_name_index: " << attribute_name_index << std::endl;
    std::cout << "\tattributes_length: " << attribute_length   << std::endl;
    std::cout << "\tconstant_value_index: " << constantvalue_index << std::endl;
}


GenericAtt::GenericAtt(u2 attribute_name_index, u4 attribute_length, u1 * att_info) {
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
    this->att_info = att_info;
}

int CodeAtt::CreateTableswitchInstruction(int index) {

    TableswitchInst* tsi = new TableswitchInst(0xaa, "tableswitch");
    int padding = 0;
    u4 default_bytes;
    u4 high_bytes;
    u4 low_bytes;

    while ((index + padding) % 4 != 0){
        padding++;
    }

    index = index + padding;

    tsi->SetPadding(padding);

    for (int i = 0; i < 4; i++) {
		default_bytes <<= 8;
		default_bytes |= code[index];
        index++;
	}

    for (int i = 0; i < 4; i++) {
		low_bytes <<= 8;
		low_bytes |= code[index];
        index++;
	}

    for (int i = 0; i < 4; i++) {
		high_bytes <<= 8;
		high_bytes |= code[index];
        index++;
	}

    tsi->SetBytes(default_bytes, high_bytes, low_bytes);

    int jump_offsets_amount = high_bytes - low_bytes + 1;

    u4 jump_offsets[jump_offsets_amount];

    for (int i = 0; i < jump_offsets_amount; i++) {
        for (int j = 0; j < 4; j++) {
            jump_offsets[i] <<= 8;
            jump_offsets[i] |= code[index];
            index++;
        }
        std::cout << jump_offsets[i] << std::endl;
    }

    tsi->SetJumpOffsets(jump_offsets);

    code_instructions.push_back(tsi);

    return index;

}

void CodeAtt::CreateCodeInstructions() {

    instructionVector.CreateInstructionVector();

    Instruction* inst;
    u1 opcode;
    int skip;
    int i = 0;

    while (i < code_length) {
        opcode = code[i];
        //skip = instructionVector.ShowInstruction(opcode, prefix);

        for (int j = 0; j < (int) instructionVector.GetSize(); j++) {
            inst = instructionVector.GetInstruction(j);
            if (opcode == inst->GetOpcode()) {
                if (opcode == 0xaa){ //tableswitch
                    i = CreateTableswitchInstruction(i);
                } else {
                    code_instructions.push_back(inst);
                    skip = inst->GetSize();
                    i = i + 1 + skip;
                }
                break;
            }
        }
    }
}

CodeAtt::CodeAtt(u2 attribute_name_index, u4 attribute_length, u2 max_stack, u2 max_locals, u4 code_length, u1* code){
    this->attribute_name_index = attribute_name_index;
    this->attribute_length = attribute_length;
    this->max_stack = max_stack;
    this->max_locals = max_locals;
    this->code_length = code_length;
    this->code = code;
    CreateCodeInstructions();
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

void CodeAtt::SetAttributesTable(AttributesTable * attributes) {
    this->attributes = attributes;
}

void CodeAtt::Show() {
    std::cout << "\t>>> Code: " << std::endl;
    std::cout << "\tAttribute_name_index: " << attribute_name_index << std::endl;
    std::cout << "\tAttributes_length: " << attribute_length << std::endl;
    std::cout << "\tMax_stack: " << max_stack << std::endl;
    std::cout << "\tMax_locals: " << max_locals << std::endl;
    std::cout << "\tCode_length: " << code_length << std::endl << std::endl;
    std::cout << "\tCode: " << std::endl << std::endl;

    int code_instructions_size = code_instructions.size();

    for (int i = 0; i < code_instructions_size; i++) {
        code_instructions.at(i)->Show();
    }
}

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
    std::cout << "\t>>> Exceptions: " << std::endl;
    std::cout << "\tattribute_name_index: " << attribute_name_index << std::endl;
    std::cout << "\tattributes_length: " << attribute_length << std::endl;
    std::cout << "\tnumber_of_exceptions: " << number_of_exceptions << std::endl;

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
    std::cout << "\t>>> SourceFile: " << std::endl;
    std::cout << "\tattribute_name_index: " << attribute_name_index << std::endl;
    std::cout << "\tattributes_length: " << attribute_length << std::endl;
    std::cout << "\tsourcefile_index: " << sourcefile_index << std::endl;
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
    std::cout << "\t>>> LineNumberTable: " << std::endl;
    std::cout << "\tattribute_name_index: " << attribute_name_index << std::endl;
    std::cout << "\tattributes_length: " << attribute_length << std::endl;
    std::cout << "\tline_number_table_length: " << line_number_table_length << std::endl;
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
    std::cout << "\t >>> LocalVariableTable: " << std::endl;
    std::cout << "\tattribute_name_index: " << attribute_name_index << std::endl;
    std::cout << "\tattributes_length: " << attribute_length << std::endl;
    std::cout << "\tlocal_variable_table_length: " << local_variable_table_length << std::endl;
}

void AttributesTable::AppendConstantValue(u2 attribute_name_index, u4 attribute_length, u2 constantvalue_index){
    at.push_back(new ConstantValueAtt(attribute_name_index, attribute_length, constantvalue_index));
}


void AttributesTable::AppendCode(u2 attribute_name_index, u4 attribute_length, u2 max_stack, u2 max_locals, u4 code_length, u1 * code){
    at.push_back(new CodeAtt(attribute_name_index, attribute_length, max_stack, max_locals, code_length, code));
}


void AttributesTable::AppendExceptions(u2 attribute_name_index, u4 attribute_length){
    at.push_back(new ExceptionsAtt(attribute_name_index, attribute_length));
}


void AttributesTable::AppendSourceFile(u2 attribute_name_index, u4 attribute_length, u2 sourcefile_index){
    at.push_back(new SourceFileAtt(attribute_name_index, attribute_length, sourcefile_index));
}


void AttributesTable::AppendLineNumberTable(u2 attribute_name_index, u4 attribute_length){
    at.push_back(new LineNumberTableAtt(attribute_name_index, attribute_length));
}


void AttributesTable::AppendLocalVariableTableAtt(u2 attribute_name_index, u4 attribute_length){
    at.push_back(new LocalVariableTableAtt(attribute_name_index, attribute_length));
}

void AttributesTable::AppendGeneric(u2 attribute_name_index, u4 attribute_length, u1 * info) {
    at.push_back(new GenericAtt(attribute_name_index, attribute_length, info));
}


void AttributesTable::LoadAttributesTable(std::istream& file, int attributes_count, ConstantPool* constant_pool) {

    u2 attribute_name_index;
    u4 attribute_length;
    u1* att_info;
    u1* attribute_name;

        for (int i = 0; i < attributes_count; i++){

            attribute_name_index = Readu2Raw(file);
            attribute_length = Readu4Raw(file);
            attribute_name = constant_pool->GetUtf8(attribute_name_index-1);        
            
            if (strcmp((const char*)attribute_name, "ConstantValue") == 0) {
                u2 constantvalue_index = Readu2Raw(file);
                AppendConstantValue(attribute_name_index, attribute_length, constantvalue_index);
            }


            else if (strcmp((const char*)attribute_name, "Code") == 0) {
                u2 max_stack = Readu2Raw(file);
                u2 max_locals = Readu2Raw(file);
                u4 code_length = Readu4Raw(file);
                u1* code = Readu1(file, code_length);

                CodeAtt* code_att = new CodeAtt(attribute_name_index, attribute_length, max_stack, max_locals, code_length, code);
                
                u2 exception_table_length = Readu2Raw(file);
                code_att->SetExceptionTableLength(exception_table_length);

                for (int i = 0; i < exception_table_length; i++) {
                    code_att->AppendException(new ExceptionsTableAtt(Readu2Raw(file), Readu2Raw(file), Readu2Raw(file), Readu2Raw(file)));
                }
                
                u2 code_attributes_count = Readu2Raw(file);
                if (code_attributes_count) {
                    AttributesTable * at = new AttributesTable();
                    at->LoadAttributesTable(file, code_attributes_count, constant_pool);
                    code_att->SetAttributesTable(at);
                }
                at.push_back(code_att);
            }

            else if (strcmp((const char*)attribute_name, "Exceptions") == 0) {
                ExceptionsAtt * exp_att = new ExceptionsAtt(Readu2Raw(file), Readu4Raw(file));
                u2 number_of_exceptions = Readu2Raw(file);

                exp_att->SetExceptionsIndexTableSize(number_of_exceptions);

                for(int i = 0; i< number_of_exceptions; i++){
                    exp_att->AppendExceptionIndex(new ExceptionsIndexTable(Readu1(file)));
                }   
            }
            
            else if (strcmp((const char*)attribute_name, "SourceFile") == 0) {
                u2 constantvalue_index = Readu2Raw(file);
                AppendSourceFile(attribute_name_index, attribute_length, constantvalue_index);
            } 

            else if (strcmp((const char*)attribute_name, "LineNumberTable") == 0) {
               LineNumberTableAtt * line_att = new LineNumberTableAtt(attribute_name_index, attribute_length);
               u2 line_number_table_length = Readu2Raw(file);
               line_att->SetLineNumberTableLength(line_number_table_length);

                for (int i = 0; i < line_number_table_length; i++) {
                    line_att->AppendNumber(new LineNumberTable(Readu2Raw(file), Readu2Raw(file)));
                }
                at.push_back(line_att);
            }

            else if (strcmp((const char*)attribute_name, "LocalVariable") == 0) {
                LocalVariableTableAtt * local_att = new LocalVariableTableAtt(Readu2Raw(file), Readu2Raw(file));
                u2 local_variable_table_length = Readu2Raw(file);

                local_att->SetLocalVariableTableLength(local_variable_table_length);
            
                for (int i = 0; i < local_variable_table_length; i++) {
                    local_att->AppendVariable(new LocalVariableTable(Readu2Raw(file), Readu2Raw(file),Readu2Raw(file), Readu2Raw(file)));
                }
                at.push_back(local_att);
            }

            else {
                att_info = Readu1(file, attribute_length);
                AppendGeneric(attribute_name_index, attribute_length, att_info);
            }
               
        }
};

void AttributesTable::ShowAttributesTable() {
    for (int i = 0; i < (int)at.size(); i++){
        at.at(i)->Show();
    }
}