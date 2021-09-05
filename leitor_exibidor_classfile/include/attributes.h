#ifndef ATTRIBUTES
#define ATTRIBUTES

#include "data_class_format.h"
#include <vector>

class Attributes_info{
    protected:
    u2 attribute_name_index;
    u4 attribute_length;
    public:
    u2 GetAttributeNameIndex();
    u4 GetAttributeLength();
};

class Attributes_table{
    protected:
        std::vector<Attributes_info *> at;
    public:
        void AppendConstantValue(u2 attribute_name_index, u4 attribute_length, u2 constantvalue_index);
        void AppendCode(u2 attribute_name_index, u4 attribute_length, u2 max_stack, u2 max_locals, u4 code_length);
        void AppendExceptions(u2 attribute_name_index, u4 attribute_length, u2 number_of_exceptions);
        void AppendSourceFile(u2 attribute_name_index, u4 attribute_length, u2 sourcefile_index);
        void AppendLineNumberTable(u2 attribute_name_index, u4 attribute_length, u2 line_number_table_length);
        void AppendLocalVariableTableAtt(u2 attribute_name_index, u4 attribute_length, u2 local_variable_table_length);
        void ShowAttributesTable();
};



class ConstantValueAtt : public Attributes_info{
    protected:
        u2 constantvalue_index;
    public:
        ConstantValueAtt(u2 attribute_name_index, u4 attribute_length, u2 constantvalue_index);
};




class Code{
    protected:
        u1 instructions;
};


class ExceptionsTable{
    protected:
        u2 exceptions_table_length;
        u2 start_pc;
        u2 end_pc;
        u2 handler_pc;
        u2 catch_type;   
};


class CodeAtt : public Attributes_info{
    protected:
        u2 max_stack;
        u2 max_locals;
        u4 code_length;
        u2 exception_table_length;
        ExceptionsTable* exception_table;
        u2 attributes_count;
    public:
        CodeAtt(u2 attribute_name_index, u4 attribute_length, u2 max_stack, u2 max_locals, u4 code_length);
};


class ExceptionIndexTable{
    protected:
        u2 index;
};



class ExceptionsAtt : public Attributes_info{
    protected:
        u2 number_of_exceptions;
        ExceptionIndexTable * exeption_index_table;
    public:
        ExceptionsAtt(u2 attribute_name_index, u4 attribute_length, u2 number_of_exceptions);

};


class SourceFileAtt : public Attributes_info{
    protected:
        u2 sourcefile_index;
    public:
        SourceFileAtt(u2 attribute_name_index, u4 attribute_length, u2 sourcefile_index);
};


class LineNumberTable{
    protected:
        u2 start_pc;
        u2 line_number;
};


class LineNumberTableAtt : public Attributes_info{
    protected:
        u2 line_number_table_length;
        LineNumberTable * line_number_table;
    public:
        LineNumberTableAtt(u2 attribute_name_index, u4 attribute_length, u2 line_number_table_length);
};


class LocalVariableTable{
    protected:
        u2 start_pc;
        u2 name_index;
        u2 descriptor_index;
        u2 index;
};


class LocalVariableTableAtt : public Attributes_info{
    protected:
        u2 local_variable_table_length;
        LocalVariableTable * local_variable_table;
    public:
        LocalVariableTableAtt(u2 attribute_name_index, u4 attribute_length, u2 local_variable_table_length);
};



#endif