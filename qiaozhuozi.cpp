#include<iostream>
using namespace std;
int main()
{
	for(int n=1;n<100;n++)
	{
		int a=n%10;
		int b=n/10;
		int c=n%7; 
		if(a==7||b==7||c==0)
		{
			cout<<"ÇÃ×À×Ó"<<endl;
		}
		else{
			cout<<n<<endl;
		} 
	}
return 1;
}
 
