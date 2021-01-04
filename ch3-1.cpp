/*实现计算器的功能，可以对多个实数进行四则混合运算。*/
/*此程序可以实现混合运算，并且能够接受带括号的运算，比较接近计算器。*/
#include <iostream>
#include"Oprate.h"

using namespace std;

int main()
{
    char a,b,c,theta,x;
    Calculator s;
	cout<<"Enter string:(end with '#'):"<<endl;
	cout<<"计算的数字必须是1位数"<<endl;
	cin>>c;
	while (c!='#'||s.GetTop('T')!='#')//当输入#的时候，可以进行完求值。否则无法运行完。
	{
		if (c>='1'&&c<='9')//如果是运算数就直接存入
		{
			s.Push('N',c);
			cin>>c;
		}
		else//本算法是以运算符为核心，只有当下一个运算符输入进来，才视为上一次的运算数输入完毕。
			//将栈顶的运算符与新输入的运算符比较，才开始进行数的操作
		{
			switch (s.Precede(s.GetTop('T'),c))
			{
				case '<'://准备进行下一次的运算
					s.Push('T',c);
					cin>>c;
					break;
				case '='://脱括号
					s.Pop('T',x);
					cin>>c;
					break;
				case '>'://进行先前一个的运算
					s.Pop('T',theta);
					s.Pop('N',a);
					s.Pop('N',b);
					s.Push('N',s.Operate(b,theta,a));
					break;
			}

		}
	}
	cout<<"result="<<s.GetTop('N')-48<<endl;
	return 1;
}
