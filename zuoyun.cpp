#include<iostream>
using namespace std;
class Person
{
	friend ostream& operator<<(ostream &cout,Person &p ) ;
	public:
	Person()
	{
		a=10;
		b=10;
	}
	private :
		int a;
		int b;
};
ostream& operator<<(ostream &cout,Person &p ) 
{
	cout<<p.a<<" "<<p.b;
	return cout;
};
int main()
{
	Person p;
	cout<<p<<"helli";
	return 0;
}
 
