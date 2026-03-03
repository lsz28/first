#include <iostream>
using namespace std;
#include <string>

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

//打印学生信息的函数
//1、值传递
void printStudent1(struct student s)
{
	s.age = 100;
    cout << "子函数 值传递前 姓名：" << s.name << "年龄：" << s.age << "分数：" << s.score << endl;

    
}

//2、地址传递
void printStudent2(student* p)//当然可以去掉struct 
{
	p->score = 90;//改属性 
    cout << "子函数 地址传递前 姓名：" << p->name << "年龄：" << p->age << "分数：" << p->score << endl;

    
}

int main()
{
    //结构体做函数参数
    //将学生传入到一个参数中，打印学生身上的所有信息

    //创建结构体变量
    struct student s;
    s.name = "张三";
    s.age = 20;
    s.score = 85;

    cout << "main函数 传递前 姓名：" << s.name << "年龄：" << s.age << "分数：" << s.score << endl;

    printStudent1(s);

    cout << "子函数  值传递后 姓名：" << s.name << "年龄：" << s.age << "分数：" << s.score << endl;

    printStudent2(&s);

    cout << "子函数 地址传递后 姓名：" << s.name << "年龄：" << s.age << "分数：" << s.score << endl;


    cout << "main函数 传递后 姓名：" << s.name << "年龄：" << s.age << "分数：" << s.score << endl;

    

    return 0;

}
