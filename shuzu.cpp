//数组;
//a[]

//1,int arr[数字];
//2,int arr[数字]={1,2,3} 
//3,int arr[] ={1,2,3}

#include<iostream>
using namespace std;
int main()
{
//	1
//	int arr[5];
//	arr[0] =1;//从0开始
//	arr[1]=2;
//	arr[2]=3;
//	for(int i=0;i<5;i++) 
//	{
//		cout<<arr[i]<<endl;//第四个和第五个并未被初始化,所以随机输出 
//	}




//	int arr[5] ={1,2,3};
//	for(int i=0;i<5;i++)
//	{
//		cout<<arr[i];//这时候因为在上面一起被初始化了,所以45会被默认为0 
//	}


    int arr[]={1,2,3,4,5} ;
    for(int i=0;i<5;i++)
	{
		cout<<arr[i];
	}
	
	
	
return 0;
} 
