#include <iostream>
using namespace std;

int main()
{
    //空指针
    //1、空指针用于给指针变量进行初始化
    int *p = NULL;//定义为空指针 

    //2、空指针是不可以进行访问的
    //0~255之间的内存编号是系统占用的，因此不可以访问。
    //对空指针解引用，然后操作它，这样是报错的
	*p = 256;  //不管怎么改都是空指针,无法访问 
    cout<<*p;
    system("pause");   //按任意键继续

    return 0;

}
