#include<bits/stdc++.h>
using namespace std;
class Fushu
{
	public:
		int shi;
		int shu;
	friend istream& operator>>(istream& is,Fushu& f);
	friend ostream& operator<<(ostream& os,const Fushu& f);
	Fushu operator+(const Fushu&b);
	Fushu(){};
};
istream& operator>>(istream& is,Fushu& f)
{
	char ch,chh;
	is>>f.shi>>ch>>f.shu>>chh;
	return is;
}
ostream& operator<<(ostream& os,const Fushu& f)
{
	os<<f.shi<<"+"<<f.shu<<"i";
	return os;
}
Fushu Fushu::operator+(const Fushu&b)
{
	Fushu a;
	a.shi=this->shi+b.shi;
	a.shu=this->shu+b.shu;
	return a;
}
int main()
{
	Fushu f;
	cin>>f;
	Fushu ff;
	cin>>ff;
	cout<<f+ff<<endl;
}
