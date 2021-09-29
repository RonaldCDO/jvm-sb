#ifndef FRAME
#define FRAME

#include "data_class_format.h"
#include "methods.h"
#include <stack>
#include "constant_pool.h"


class StackOp{
    protected:
    u2 op;
    MethodsInfo* mi;  

    public:
    inline u2 GetOp(){return op;};
};


class LocalVariable{
    protected:
    u2 op;
    ConstantPoolInfo* ci;
    public:
};

class Frame{
    protected:
        std::stack<StackOp*> op;
        std::vector<LocalVariable*> localVariables;
        u4 PC;
        u2 codeIndex;
        u2 methodIndex;
    public:

};

#endif