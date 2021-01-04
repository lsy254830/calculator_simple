#include<iostream>
#include"Oprate.h"

using namespace std;

Calculator::Calculator()
{
        OPND.base=new SElemType;
        OPTR.base=new SElemType;
        if (!(OPTR.base&&OPND.base))
            cout<<"error!"<<endl;
        OPTR.top=OPTR.base;
        OPND.top=OPND.base;
        OPTR.stacksize=OPND.stacksize=STACK_INIT_SIZE;
        *OPTR.top++='#';
}
int Calculator::Push(char x,char c)
{
        if (x=='T')
        {
            *OPTR.top=c;
            OPTR.top++;
        }
        else if (x=='N')
        {
            *OPND.top=c;
            OPND.top++;
        }

        return OK;
}
int Calculator::Pop(char x,char &c)
{
        if (x=='T')
            c=*--OPTR.top;
        else if (x=='N')
            c=*--OPND.top;

        return OK;
}
int Calculator::GetTop(char x)
{
        if (x=='T')
            return *(OPTR.top-1);
        else if(x=='N')
            return *(OPND.top-1);
        return 0;
}
int Calculator::Precede(char a,char b)
{
        if (a=='+'||a=='-')
        {
            if (b=='*'||b=='/'||b=='(')
                return '<';
            else return '>';
        }
        if (a=='*'||a=='/')
        {
            if (b=='(')
                return '<';
            else return '>';
        }
        if (a=='(')
        {
            if (b==')')
                return '=';
            else return '<';
        }
        if (a==')')
            return '>';
        if (a=='#')
        {
            if (b=='#')
                return '=';
            else return '<';
        }
        return 0;
}
int Calculator::Operate(char a,char theta,char b)
{
        int m,n;
        m=a-48;
        n=b-48;
        switch (theta)
        {
        case '+':return m+n+48;
            case '-':return m-n+48;
                case '*':return m*n+48;
                    case '/':return m/n+48;
                    default:return 0;
        }
        return 0;
}
