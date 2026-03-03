//逻辑运算符 输出的仍然是0 1,然后输入的0是指假,其余的指真 
/* ! 非 即反过来的意思 
&& 和 就是两个都得满足是真,则为真 
|| 或 两个有一个满足是真就是真*/

#include <iostream>
using namespace std;
int main()
{
	int a=1;
	int b;

	cout<<!a<<endl;
	cout<<!!a<<endl;//可以加两否
	
	a=0,b=0;
	cout<<(a&&b)<<endl;//;逻辑运算直接打出来 0/1 
	
	
	a=1,b=0;
	cout<<(a&&b)<<endl;
	
	a=100,b=99;
	cout<<(a&&b)<<endl;
	
	a=1,b=0;
	cout<<(a||b)<<endl;//有一个是真的 
	 
	
	return 1;
} 
