#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;//n个数
	int p[n]; 
    for(int j=0;j<n;j++)
    {
        cin>>p[j];
    }
    while(p[n-1]!=n)
    {
    	int temp=p[n-1] ;
    	for(int i=n-1;i>0;i--)//往后赋值 
		{
			
       	p[i]=p[i-1];//是将=后的值赋到=前的值 
       	   		
		}
		p[0]=temp;
		for(int j=0;j<n;j++)
    {
	cout<<p[j]<<" ";    	
	}
	cout<<endl;

	}
    
	
	return 0;

        

}
