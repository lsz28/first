#include<bits/stdc++.h>
using namespace std;
const int Max=10;
class hezi
{
	//属性
	private:
	int* data;
	int MAX;
	int LEN; 
	//构造函数,所有初始化
	public:
	hezi(int max=Max)
	{
		data=new int[max];
		MAX=max;
		LEN=0;
	}
	//析构函数,把new的delete掉,然后在初始化为0 
	~hezi()
	{
		delete[] data;
		MAX==0;
		LEN=0;
	}
	void inc(int len)
{
	if(LEN>=MAX)
	exit(1);
	int* p=data;
	data=new int[MAX+len];
	for(int i=0;i<LEN;i++)
    {
    	data[i]=p[i];
	}
	MAX+=len;
}
void pri()
{
	for(int i=0;i<LEN;i++)
	{
		cout<<data[i]<<" ";
	}
	cout<<endl;
	cout<<LEN<<endl;
	cout<<MAX;
}
void ins(int w,int shu)
{
	if(w<0||w>LEN||LEN>=MAX)
	exit(1);
	for(int i=LEN;i>w;i--)
	{
		data[i]=data[i-1];
	}
	data[w]=shu;
	LEN+=1;
}
void era(int w)
{
	if(w<0||LEN<=0)
	exit(0);
	for(int i=w;i<LEN-1;i++)
	{
		data[i]=data[i+1];
	}
	LEN-=1;
}
};
//扩展函数
//先判断能否(是否大于等于最大值)
//然后存储,新内存,赋值,改length

//插入函数
//判断能否插入,是否小于0,能否再插入,是否超过最大范围
//从后面往前开始放,然后再插入 
int main()
{
	hezi h(10);
	h.ins(0,1);
	h.ins(1,2);
	h.ins(2,4);
	h.era(2);
	h.inc(10);
	h.pri();
}
