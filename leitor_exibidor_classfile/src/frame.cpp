#include "frame.h"
#include "instructions.h"
#include "operacoes.h"

// Frame::Frame (ClassFile *l){
//     frame *aux = (frame*) malloc(sizeof(frame));

// }

void Frame::execute(){
	while (nextInstruction())
	{
		Operacoes::run(opcode);
	}
}

bool Frame::nextInstruction(){
    if (framestack.empty()){
        return false;
    }
    if ((framestack.top()->pc - framestack.top()->m.attributes->GetAttributeInfo()->GetCode()) < 
        framestack.top()->m.attributes->GetAttributeInfo()->GetAttributeLength()){

        opcode = *framestack.top()->pc;
        framestack.top()->pc++;
        return true;
    }

    framestack.pop();
    if (framestack.empty()){
        return false;
    }

    return true;
}
