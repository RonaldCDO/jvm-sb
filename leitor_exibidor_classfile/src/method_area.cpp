#include "method_area.h"

MethodArea::MethodArea(char* fileName) {
    mainClass = new ClassFile();
    mainClass->LoadFile(fileName);
    mainClass->ShowSuperClass();
    mainClass->ShowInterfaces();
    mainClass->ShowFields();
    mainClass->ShowMethods();
}