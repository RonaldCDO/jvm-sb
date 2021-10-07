#ifndef METHOD_AREA
#define METHOD_AREA

#include "classfile.h"
#include "frame.h"

class MethodArea {
    private:
        std::vector<ClassFile> RuntimeClassVector;
        ClassFile* mainClass;
    public:
        MethodArea(char* fileName);
        void addRuntimeClass(char* className);
};

class Object{

};

#endif