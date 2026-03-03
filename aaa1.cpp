#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	//创建二维数组,然后一行一行打印
	int arr[101][101];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
//	cout<<"i";
    
	//循环每行,然后用min加循环找出最小值并打印 
	for(int i=0;i<n;i++)
	{
		int min=arr[i][0];
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]<min)
			min=arr[i][j];
		}
		cout<<min<<'\n';
	}
}
