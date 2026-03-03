//如果函数需要一个结果(数值,状态),就一定要有返回值
//如果只需执行一个动作,那就可以没有返回值 


#include <iostream>
using namespace std;

//函数常见样式
//1、无参无返
void test01()//没有返回值写void 
{
    cout << "this is test01" << endl;
}

//2、有参无返
void test02(int a)
{
    cout << "this is test 02 a = " << a << endl;
}

//3、无参有返
int test03()
{
    cout << "this is test 03 " << endl;

    return 1000;
}

//4、有参有返
int test04(int a )
{
    cout << "this is test 04 a = " << a << endl;

    return 10;//返回值就是指操作完以上的代码最后数值会回到返回值 
}

int main()
{
    //无参无返函数调用
    test01();

    //有参无返函数调用
    test02(100);

    //无参有返函数调用
    int num1 = test03();
    cout << "num1 = " << num1 << endl;

    //有参有返函数调用
    int num2 = test04(10000);//这里会调用一次函数,然后再通过返回值赋值 
    cout << "num2 = " << num2 << endl;

    system("pause");   //按任意键继续

    return 0;

}
