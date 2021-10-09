#ifndef ATTRIBUTES
#define ATTRIBUTES

#include "data_class_format.h"
#include "instructions.h"
#include "constant_pool.h"
#include <vector>
#include <iostream>
#include <string.h>

class AttributesInfo{
    protected:
    u2 attribute_name_index;
    u4 attribute_length;
    u1 * code;
    public:
    inline u2 GetAttributeNameIndex() {return attribute_name_index;};
    inline u4 GetAttributeLength() {return attribute_length;};
    inline u1 * GetCode() {return code;};
    virtual void Show();
};

class AttributesTable{
    protected:
        // std::vector<AttributesInfo *> at;
    public:
        std::vector<AttributesInfo *> at;
        void AppendConstantValue(u2 attribute_name_index, u4 attribute_length, u2 constantvalue_index);
        void AppendCode(u2 attribute_name_index, u4 attribute_length, u2 max_stack, u2 max_locals, u4 code_length, u1 * code);
        AttributesInfo * GetAttributeInfo();
        void AppendExceptions(u2 attribute_name_index, u4 attribute_length);
        void AppendSourceFile(u2 attribute_name_index, u4 attribute_length, u2 sourcefile_index);
        void AppendLineNumberTable(u2 attribute_name_index, u4 attribute_length);
        void AppendLocalVariableTableAtt(u2 attribute_name_index, u4 attribute_length);
        void AppendGeneric(u2 attribute_name_index, u4 attribute_length, u1* att_info);
        void AppendAttribute(AttributesInfo * attribute);
        void ShowAttributesTable();
        void LoadAttributesTable(std::istream& file, int attributes_count, ConstantPool* constant_pool);
};


class ConstantValueAtt : public AttributesInfo{
    protected:
        u2 constantvalue_index;
    public:
        ConstantValueAtt(u2 attribute_name_index, u4 attribute_length, u2 constantvalue_index);
        void Show();
};

class GenericAtt : public AttributesInfo{
    protected:
        u1 * att_info;
    public:
        GenericAtt(u2 attribute_name_index, u4 attribute_length, u1* att_info);
};


class ExceptionsTableAtt{
    protected:
        u2 start_pc;
        u2 end_pc;
        u2 handler_pc;
        u2 catch_type;   
    public:
        ExceptionsTableAtt(u2 start_pc, u2 end_pc, u2 handler_pc, u2 catch_type);
        void Show();
};


class CodeAtt : public AttributesInfo{
    protected:
        u2 max_stack;
        u2 max_locals;
        u4 code_length;
        u1* code;
        u2 exception_table_length;
        std::vector<ExceptionsTableAtt*> exceptions_table;
        u2 attributes_length;
        AttributesTable * attributes;
    public:
        inline u1 * GetCode() {return code;};
        CodeAtt(u2 attribute_name_index, u4 attribute_length, u2 max_stack, u2 max_locals, u4 code_length, u1 * code);
        void SetExceptionTableLength(u2 length);
        void SetAttributesLength(u2 length);
        void AppendException(ExceptionsTableAtt * eta);
        void SetAttributesTable(AttributesTable * attributes);
        void Show();
};


class ExceptionsIndexTable{
    protected:
        u1 indexes;
    public:
    ExceptionsIndexTable(u1 indexes);
};

class ExceptionsAtt : public AttributesInfo{
    protected:
        u2 number_of_exceptions;
        std::vector<ExceptionsIndexTable *> exception_index_table;
    public:
        ExceptionsAtt(u2 attribute_name_index, u4 attribute_length);
        void SetExceptionsIndexTableSize(u2 length);
        void AppendExceptionIndex(ExceptionsIndexTable* eit);
        void Show();
};


class SourceFileAtt : public AttributesInfo{
    protected:
        u2 sourcefile_index;
        
    public:
        SourceFileAtt(u2 attribute_name_index, u4 attribute_length, u2 sourcefile_index);
        void Show();
};


class LineNumberTable{
    protected:
        u2 start_pc;
        u2 line_number;
    public:
        LineNumberTable(u2 start_pc, u2 line_number);
        void Show();
};


class LineNumberTableAtt : public AttributesInfo{
    protected:
        u2 line_number_table_length;
        std::vector<LineNumberTable *> line_number_table;
    public:
        LineNumberTableAtt(u2 attribute_name_index, u4 attribute_length);
        void SetLineNumberTableLength(u2 length);
        void AppendNumber(LineNumberTable * lnt);
        void Show();
};


class LocalVariableTable{
    protected:
        u2 start_pc;
        u2 name_index;
        u2 descriptor_index;
        u2 index;
    public:
        LocalVariableTable(u2 start_pc, u2 name_index, u2 descriptor_index, u2 index);
};


class LocalVariableTableAtt : public AttributesInfo{
    protected:
        u2 local_variable_table_length;
        std::vector<LocalVariableTable*> local_variable_table;
    public:
        LocalVariableTableAtt(u2 attribute_name_index, u4 attribute_length);
        void SetLocalVariableTableLength(u2 length);
        void AppendVariable(LocalVariableTable * lvt);
        void Show();
};

#endif