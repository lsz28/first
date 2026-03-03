//乘法口诀表
//首先要思考怎么打出口诀表的形式

#include<iostream>
using namespace std;
int main()
{
	for(int i=1;i<10;i++)
	{
		for(int j=1;j<i;j++)
		{
			cout<<j<<"*"<<i<<"="<<i*j<<" \t";
		}
		cout<<endl;
	}
return 0;
} 
