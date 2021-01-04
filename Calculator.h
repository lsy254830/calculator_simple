#ifndef OPRATE_H_INCLUDED
#define OPRATE_H_INCLUDED
#include<iostream>
using namespace std;
const int STACK_INIT_SIZE=100;
const int STACKINCREMENT=10;
const int OK=1;
const int ERROR=0;
const int OVERFLOW=-2;

typedef char SElemType;
typedef struct Stack
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;


class Calculator
{
        public:
            Calculator();
            int Push(char x,char c);
            int Pop(char x,char &c);
            int GetTop(char x);
            int Precede(char a,char b);
            int Operate(char a,char theta,char b);
        private:
            SqStack OPND;//存放操作数和操作结果
            SqStack OPTR;//存放操作符号

};


#endif // OPRATE_H_INCLUDED
