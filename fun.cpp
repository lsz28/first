#include<bits/stdc++.h>
using namespace std;
class father
{
	public:
		int age;
		string name;
	father()
	{
		age=95;
		name="fat";
	}
};
class son:public father
{
	public:
		int age;
		string name; 
		son(int a,string b)
		{
			age=a;
			name=b;
		}
};
int main()
{
	son s(10,"son");
	cout<<s.age<<s.name<<endl;
	cout<<s.father::age<<s.father::name<<endl;
}
