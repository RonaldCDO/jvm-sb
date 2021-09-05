#ifndef ATTRIBUTES
#define ATTRIBUTES

#include "data_class_format.h"
#include <vector>
#include <iostream>

class AttributesInfo{
    protected:
    u2 attribute_name_index;
    u4 attribute_length;
    public:
    u2 GetAttributeNameIndex();
    u4 GetAttributeLength();
    virtual void Show();
};

class AttributesTable{
    protected:
        std::vector<AttributesInfo *> at;
    public:
        void AppendConstantValue(u2 attribute_name_index, u4 attribute_length, u2 constantvalue_index);
        void AppendCode(u2 attribute_name_index, u4 attribute_length, u2 max_stack, u2 max_locals, u4 code_length);
        void AppendExceptions(u2 attribute_name_index, u4 attribute_length, u2 number_of_exceptions);
        void AppendSourceFile(u2 attribute_name_index, u4 attribute_length, u2 sourcefile_index);
        void AppendLineNumberTable(u2 attribute_name_index, u4 attribute_length, u2 line_number_table_length);
        void AppendLocalVariableTableAtt(u2 attribute_name_index, u4 attribute_length, u2 local_variable_table_length);
        void ShowAttributesTable();
        // void LoadAttributesTable();
};



class ConstantValueAtt : public AttributesInfo{
    protected:
        u2 constantvalue_index;
    public:
        ConstantValueAtt(u2 attribute_name_index, u4 attribute_length, u2 constantvalue_index);
};

class GenericAtt : public AttributesInfo{
    protected:
        u1 * att_info;
    public:
        GenericAtt(u2 attribute_name_index, u4 attribute_length, u1* att_info);
};


class Code{
    protected:
        u1 instructions;
};


class ExceptionsTableAtt{
    protected:
        u2 start_pc;
        u2 end_pc;
        u2 handler_pc;
        u2 catch_type;   
    public:
        ExceptionsTableAtt(u2 start_pc, u2 end_pc, u2 handler_pc, u2 catch_type);
};


class CodeAtt : public AttributesInfo{
    protected:
        u2 max_stack;
        u2 max_locals;
        u4 code_length;
        std::vector<u1*> code;
        u2 exception_table_length;
        std::vector<ExceptionsTableAtt*> exceptions_table;
        u2 attributes_length;
        std::vector<GenericAtt*> attributes_table;
    public:
        CodeAtt(u2 attribute_name_index, u4 attribute_length, u2 max_stack, u2 max_locals, u4 code_length);
        void SetExceptionTableLength(u2 length);
        void SetAttributesLength(u2 length);
        void AppendException(ExceptionsTableAtt * eta);
        void AppendAttribute(GenericAtt * ga);
        void Show();
};


class ExceptionsIndexTable{
    protected:
        std::vector<u2*> index_table;
};



class ExceptionsAtt : public AttributesInfo{
    protected:
        u2 number_of_exceptions;
        ExceptionsIndexTable * exception_index_table;
    public:
        ExceptionsAtt(u2 attribute_name_index, u4 attribute_length, u2 number_of_exceptions);

};


class SourceFileAtt : public AttributesInfo{
    protected:
        u2 sourcefile_index;
        
    public:
        SourceFileAtt(u2 attribute_name_index, u4 attribute_length, u2 sourcefile_index);
};


class LineNumberTable{
    protected:
        u2 start_pc;
        u2 line_number;
    public:
        LineNumberTable(u2 start_pc, u2 line_number);
};


class LineNumberTableAtt : public AttributesInfo{
    protected:
        u2 line_number_table_length;
        std::vector<LineNumberTable *> line_number_table;
    public:
        LineNumberTableAtt(u2 attribute_name_index, u4 attribute_length, u2 line_number_table_length);
        void AppendNumber(LineNumberTable * lnt);
};


class LocalVariableTable{
    protected:
        u2 start_pc;
        u2 name_index;
        u2 descriptor_index;
        u2 index;
};


class LocalVariableTableAtt : public AttributesInfo{
    protected:
        u2 local_variable_table_length;
        LocalVariableTable * local_variable_table;
    public:
        LocalVariableTableAtt(u2 attribute_name_index, u4 attribute_length, u2 local_variable_table_length);
};



#endif