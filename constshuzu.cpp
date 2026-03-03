#include <iostream>
using namespace std;
#include <string>

//const 的使用场景

struct student
{
    //姓名
    string name;
    //年龄
    int age;
    //分数
    int score;
};

//将函数中形参设置为指针，用地址传递，而不是值传递，可以减少内存空间，而且不会复制新的副本
//值传递需要复制新的副本，如果有成千上万个学生调用结构体，会复制成千上个副本
void printStudents(const student* s)//const放前面,说明常量不能变 
{
    s->age = 150;  //报错，因为假如const之后，一旦有修改的操作就会报错，可以防止我们的误操作。
    cout << "姓名：" << s->name << "年龄：" << s->age << "分数：" << s->score << endl;
}


int main()
{
    //创建结构体变量
    struct student s = { "张三",15,70 };

    //通过函数打印结构体变量信息
    printStudents(&s);

    cout << "main中张三年龄为：" << s.age << endl;

    system("pause");

    return 0;

}
