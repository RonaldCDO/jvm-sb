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
        void AppendConstantValue(u2 attribute_name_index, u4 attribute_length,
                                 u2 constantvalue_index);
        void AppendCode(u2 attribute_name_index, u4 attribute_length,
                        u2 max_stack, u2 max_locals, u4 code_length);
        void AppendExceptions(u2 attribute_name_index, u4 attribute_length,
                                 u2 number_of_exceptions);
        void AppendSourceFile(u2 attribute_name_index, u4 attribute_length,
                                 u2 sourcefile_index);
        void AppendLineNumberTable(u2 attribute_name_index, u4 attribute_length,
                                 u2 line_number_table_length);
        void AppendLocalVariableTableAtt(u2 attribute_name_index, u4 attribute_length,
                                 u2 local_variable_table_length);
        void ShowAttributesTable();

};



class ConstantValue : public Attributes_info{
    u2 constantvalue_index;
};

class Code{
    
};


class ExceptionsIndexTable{
    protected:
        u2 exceptions_table_length;
        std::vector<Exceptions *> et;
        u2 start_pc;
        u2 end_pc;
        u2 handler_pc;
        u2 catch_type;   
};

class CodeAtt : public Attributes_info{
    u2 max_stack;
    u2 max_locals;
    u4 code_length;
    // u1 code[code_length];
    // u2 exception_table_length;
    // u2 start_pc;
    // u2 end_pc;
    // u2 handler_pc;
    // u2 catch_type;
    ExceptionsIndexTable exception_table;
    // exception_table[exception_table_length];
    u2 attributes_count;
    //attribute_info attributes[attributes_count];
};




class Exceptions : public Attributes_info{
    u2 number_of_exceptions;
    // u2 exception_index_table[number_of_exceptions];
};


class SourceFile : public Attributes_info{
    u2 sourcefile_index;
};


class LineNumberTable{

};


class LineNumberTableAtt : public Attributes_info{
    u2 line_number_table_length;
    u2 start_pc;
    u2 line_number;
    // line_number_table[line_number_table_length];
};


class LocalVariableTable{

};


class LocalVariableTableAtt : public Attributes_info{
    u2 local_variable_table_length;
    u2 start_pc;
    u2 name_index;
    u2 descriptor_index;
    u2 index;
    // local_variable_table[local_variable_table_length];
};



#endif