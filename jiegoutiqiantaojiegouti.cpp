#include <iostream>
using namespace std;
#include <string>

//因为老师的结构体里有学生的结构体，所以学生结构体要在老师结构体前面先定义
//定义学生结构体
struct student
{
    string name; //姓名
    int age; //年龄
    int score; //分数
}; 

//定义老师结构体
struct teacher
{
    int id; //教师编号
    string name; //教师姓名
    int age; //年龄
    struct student stu; //学生结构体
};

int main()
{
    //结构体嵌套结构体
    //创建老师
//    teacher t;
//    t.id = 10000;
//    t.name = "老王";
//    t.age = 50;
//    t.stu.name = "小王";
//    t.stu.age = 20;
//    t.stu.score = 60;
    teacher t=
	{
		2025,"罗",25,//常规的定义结构体的第二个方法 
		"小罗",18,150 //其实有点像第二个方法连着写下来 
	} ;//问豆包找到的简便方法 

    cout << "老师姓名：" << t.name << "老师编号：" << t.id << "老师年龄：" << t.age
        << "老师辅导的学生姓名：" << t.stu.name << "学生年龄：" << t.stu.age 
        << "学生考试分数：" << t.stu.score << endl;

    system("pause");

    return 0;

}
