//switch
/*语法:switch() 
case  :      
cout    endl;
break;

case  :
....
....

default:
....
....*/

#include <iostream>
using namespace std;
int main()
{
	int score;
	cin>>score;
	switch(score)
	{//大括号别漏了 
	case 10:
	cout<<"perfect" <<endl;
	break;
	
	case 9:
	cout<<"wonderful"<<endl;
	break;
	
	default ://即上面的都不满足 
	cout<<"just so so"<<endl;
}

//switch和if的区别
//1.if(可以放区间)  switch(只可以放整数或者字符) 
//2.switch格式更整齐并且算的速率更高 
return 1;
} 
