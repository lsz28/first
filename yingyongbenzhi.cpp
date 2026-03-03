#include <iostream>
using namespace std;

//发现是引用，转换为 int* const ref = &a;
void func(int& ref)
{
    ref = 100; //ref是引用，转换为 * ref = 100;
}

int main()
{
    int a = 10;

    //自动转换为 int * const ref = &a; 指针常量是指针不可改，引用不可更改别名。
    //虽然指针常量指向的地址不可以更改，但是地址中的值可以更改。
    int& ref = a;

    ref = 20; //内部发现ref是引用，自动帮我们转换为 *ref = 20; 解引用找到相应的数据改为20

    cout << "a：" << a << endl;
    cout << "ref："  << ref << endl;

    func(a);

    system("pause");

    return 0;

}
