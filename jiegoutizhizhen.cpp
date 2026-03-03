#include <iostream>
using namespace std;
#include <string>

//结构体指针

//定义学生结构体
struct Student
{
    string name; //姓名
    int age; //年龄
    int score; //分数
};

int main()
{
    // 1、创建学生结构体变量，这里的 struct 可以省略
    struct Student s = { "张三",18,100 };

    //2、通过指针指向结构体变量
    struct Student* p = &s;  //对s取地址， tudent * p 类似 int * p，这里的 struct 可以省略

    //3、通过指针访问结构体变量中的数据
    //通过结构体指针 访问结构体中的具体属性，需要利用'->'(注意这个是结构体,不是数组)
//    cout<<*p<<endl; (这个不能用,因为*p不确定是哪个具体元素,结构体里面有太多元素了)
    cout << "姓名：" << p->name << "年龄：" << p->age << "分数：" << p->score << endl;
    cout<<p<<endl;
    p++;
    cout<<p;

    system("pause");

    return 0;

}
