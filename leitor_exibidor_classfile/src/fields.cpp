#include "fields.h"

FieldsInfo::FieldsInfo(u2 access_flags, u2 name_index, u2 descriptor_index, u2 attributes_count){
  this->access_flags = access_flags;
  this->name_index = name_index;
  this-> descriptor_index = descriptor_index;
  this-> attributes_count = attributes_count;
}

u2 FieldsInfo::GetAccessFlags(){
  return access_flags; 
}


u2 FieldsInfo::GetNameIndex(){
  return name_index - 1; 
}


u2 FieldsInfo::GetDescriptorIndex(){
  return descriptor_index - 1; 
}


u2 FieldsInfo::GetAttributesCount(){
  return attributes_count; 
}

void Fields::appendField(FieldsInfo * fields_info) {
  fields.push_back(fields_info);
}

void FieldsInfo::SetAttributesTable(AttributesTable* at) {
  this->at = at;
}

FieldsInfo* Fields::GetField(int index) {
  return fields.at(index);
}


