/*ʵ�ּ������Ĺ��ܣ����ԶԶ��ʵ���������������㡣*/
/*�˳������ʵ�ֻ�����㣬�����ܹ����ܴ����ŵ����㣬�ȽϽӽ���������*/
#include <iostream>
#include"Oprate.h"

using namespace std;

int main()
{
    char a,b,c,theta,x;
    Calculator s;
	cout<<"Enter string:(end with '#'):"<<endl;
	cout<<"��������ֱ�����1λ��"<<endl;
	cin>>c;
	while (c!='#'||s.GetTop('T')!='#')//������#��ʱ�򣬿��Խ�������ֵ�������޷������ꡣ
	{
		if (c>='1'&&c<='9')//�������������ֱ�Ӵ���
		{
			s.Push('N',c);
			cin>>c;
		}
		else//���㷨���������Ϊ���ģ�ֻ�е���һ��������������������Ϊ��һ�ε�������������ϡ�
			//��ջ������������������������Ƚϣ��ſ�ʼ�������Ĳ���
		{
			switch (s.Precede(s.GetTop('T'),c))
			{
				case '<'://׼��������һ�ε�����
					s.Push('T',c);
					cin>>c;
					break;
				case '='://������
					s.Pop('T',x);
					cin>>c;
					break;
				case '>'://������ǰһ��������
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
