//水仙花数(个位的三次方加十位的三次方加百位的三次方等于这个数) 

#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
    int num=100;
	do{
		
		a=num%10;//个位 
		b=num/10%10;//十位 
		c=num/100;//百位
		if(a*a*a+b*b*b+c*c*c==num) 
		{
			cout<<num<<endl;
			
		}
		num++;
	}
	
	while(num<1000);
	return 0;
}
