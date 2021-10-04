#ifndef FRAME
#define FRAME

#include "data_class_format.h"
#include "classfile.h"
#include "methods.h"
#include "constant_pool.h"
#include <vector>
#include <sstream>
#include <stack>


class StackOp{
    protected:
    u2 op;
    
    public:
    inline u2 GetOp(){return op;};
};


class Frame{
    protected:
        std::stack<StackOp*> operandsStack;
        std::vector<Variable*> variablesVector;
    public:
        // Frame(ClassFile*, ConstantPool*, u2);
    
};

#endif