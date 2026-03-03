//嵌套循环(循环两次) 

#include<iostream>
using namespace std;
int main()
{
	for(int i=1;i<=10;i++)
	{
		for(int j=0;j<10;j++)//内层循环最好用j,用不同的变量 
		{
			cout<<"* ";
		}
		cout<<endl;
	} 
return 0;
}
