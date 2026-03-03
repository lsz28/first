#include<iostream>
using namespace std;
#include<string>
struct student
{
	string name;
	int score;
};

struct teacher
{
	string name;
	student stu[5];
};
int main()
{
	struct teacher tea[3]=
{

  "l1","k1",10,
		"k2",20,
		"k3",30,         //我去,天啊,赋值的花括号不会加就别乱加 
		"k4",30,
		"k5",30,
  "l2","g1",10,
		"g2",20,
		"g3",30,
		"g4",30,
		"g5",30,
  "l3","a1",10,
		"a2",20,
		"a3",30,
		"a4",40,
		"a5",30
  
};
  
	for(int i=0;i<3;i++)
	{
		cout<<"老师的名字是  "<<tea[i].name<<endl;
		for(int j=0;j<5;j++)
		{
		cout<<"带的学生"<<"名字是  "<<tea[i].stu[j].name<<"  "<<"拿的分数是  "<<tea[i].stu[j].score<<endl;
    	};//注意这里用学生时的语言 
	};
return 0;
} 
