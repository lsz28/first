#include <iostream>
using namespace std;
#include <string>
//自定义数据类型，一些类型的集合组成一个类型
//语法 struct 类型名称 { 成员列表 }
//结构体定义的时候，struct关键字不能省略
//1、创建学生数据类型：学生包括(姓名，年龄，分数)
struct Student//一整个构成数据类型 
{
    //成员列表

    //姓名
    string name;
    //年龄
    int age;
    //分数
    int score;
}s3;   //2.3 创建结构体的时候，顺便创建个结构体变量

int main()
{
    //2.1 struct Student s1  s1类似结构体的实例值，类似变量赋值：int a = 10 → 属性 变量 变量值
    //结构体创建的时候，struct 关键字可以省略；上面结构体定义的时候 struct 可以省略
    struct Student s1;
    //给s1属性赋值，通过点"."访问结构体变量中的属性
    s1.name = "张三";
    s1.age = 18;
    s1.score = 100;

    cout << "姓名：" << s1.name << "年龄:" << s1.age << "分数：" << s1.score << endl;

    //2.2 struct Student s2 = { ... }
    struct Student s2 = { "李四",19,80 };
    cout << "姓名：" << s2.name << "年龄:" << s2.age << "分数：" << s2.score << endl;
    
    //2.3 
    s3.name = "王五";
    s3.age = 20;
    s3.score = 60;

    cout << "姓名：" << s3.name << "年龄:" << s3.age << "分数：" << s3.score << endl;
    
    system("pause");

    return 0;

}
