//类声明,没具体东西 
class ClassName {
public:
    // 公有成员函数
    void function1();
    
private://没有这个也默认是私有的 
    // 私有成员变量
    int variable1;
};

//类定义

#include<iostream>
using namespace std;

class MyClass {
public://里面可以包含函数也包含属性 
    void setValue(int val)
	 {
        variable = val;
    }
 
    int getValue() {
        return variable;
    }
 
private://封装起来,外面不能改,而必须通过公开的方法来操作。
    int variable;
};
 
int main() {
    MyClass obj;  // 创建对象
    obj.setValue(10);  // 设置对象的值
    cout<< "Value: " << obj.getValue() <<endl;  // 获取对象的值
    return 0;
} 
