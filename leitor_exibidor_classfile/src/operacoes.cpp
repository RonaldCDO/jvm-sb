#include "operacoes.h"



void Operacoes::run(int opcode){
	// utilizar a instruction 

    // ou

    
    // criar uma function (fora) 
    //  tipo essa
    //  const fun Operacoes::functions[] ={
    //      &Operacoes::nop,
	//      &Operacoes::aconst_null,
	//      &Operacoes::iconst_m1,
	//      &Operacoes::iconst_0,
    // }
    // chamar com 
    // function[op] ();
}

void Operacoes::nop (){
    //0x00
}

void Operacoes::aconst_null (){
    //0x01
	// frame->operandos->push((int*)(nullptr));
}

void Operacoes::iconst_m1 (){
    //0x02
	// frame->operandos->push(int(-1));
}

void Operacoes::iconst_0 (){
    //0x03
	// frame->operandos->push(int(0));
}

void Operacoes::iconst_1 (){
    //0x04
	// frame->operandos->push(int(1));
}

void Operacoes::iconst_2 (){
    //0x05
	// frame->operandos->push(int(2));
}

void Operacoes::iconst_3 (){
    //0x06
	// frame->operandos->push(int(3));
}

void Operacoes::iconst_4 (){
    //0x07
	// frame->operandos->push(int(4));
}

void Operacoes::iconst_5 (){
    //0x08
	// frame->operandos->push(int(5));
}

void Operacoes::lconst_0 (){
    //0x09
	// frame->operandos->push(int(0));
}

void Operacoes::lconst_1 (){
    //0x0a
	// frame->operandos->push(int(1));
}

void Operacoes::fconst_0 (){
    //0x0b
	// frame->operandos->push(float(0.0f));
}

void Operacoes::fconst_1 (){
    //0x0c
	// frame->operandos->push(float(1.0f));
}

void Operacoes::fconst_2 (){
    //0x0d
	// frame->operandos->push(float(2.0f));
}

void Operacoes::dconst_0 (){
    //0x0e
	// frame->operandos->push(double(0.0d));
}

void Operacoes::dconst_1 (){
    //0x0f
	// frame->operandos->push(double(1.0d));
}