#include<bits/stdc++.h>
using namespace std;
class Person
{
	public:
		Person();
		Person(int a,string na);
		Person(const Person& b);
		~Person();
		void say(string word);
	private:
		int age;
		string name;
};
Person::Person()
{
	cout<<"无参构造函数调用"<<endl; 
}
//Person::Person(int a,string na)
//{
//	this->age=a;
//	this->name=na;
//	cout<<this->age<<this->name<<endl;
//	cout<<"有参构造函数"<<endl;
//		say("hello"); 
//}
Person::Person(int a,string na):age(a),name(na){cout<<"初始化列表"<<endl;};
Person::Person(const Person& b)
{
	age=b.age;
	name=b.name;
	cout<<"拷贝构造函数"<<endl;

} 
void Person::say(string word)
{
	cout<<word<<endl;
}
Person::~Person()
{
	cout<<this->name<<"析构函数"<<endl;
	
}
void test01()
{
	Person p1; 
//	cout<<p1.age<<p1.name;
}
void test02()
{
	Person p2;
	Person p3(10,"lsz");
	p3.say("hello");
	Person p6(p3);
	
}
int main()
{
	test01();
	test02();
}
