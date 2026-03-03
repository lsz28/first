#include<bits/stdc++.h>
using namespace std;
struct shuzu
{
	int data[100];
	int len;
};
void chushi(shuzu& s)
{
	s.len=0;
}
bool insert(shuzu& s,int w,int shu)
{
	if(w>s.len||w<0||w>=100)
	return false;
	else
	{
		for(int i=s.len;i>w;i--)
		{
			s.data[i]=s.data[i-1];
			
		}
		s.data[w]=shu;
		s.len++;
		return true;
	}
}
bool erase(shuzu& s,int w)
{
	if(w>s.len||w<0||w>=100)
	return false;
	else
	{
		for(int i=w;i<s.len-1;i++)
		{
			s.data[i]=s.data[i+1];
		}
		s.len--;
		return true;
	}
}
void print(shuzu& s)
{
	for(int i=0;i<s.len;i++)
	{
		cout<<s.data[i];
	}
	cout<<endl;
	cout<<s.len;
}
int main()
{
	shuzu l;
	chushi(l);
	insert(l,0,1);
	insert(l,1,2);
	insert(l,2,3);
	insert(l,3,4);
	erase(l,1); 
	print(l);
}
