//程序流程结构 选择结构if

#include <iostream>
using namespace std;
int main() {
	int score;
	cin>>score;
	if(score>600) { //不加;因为跟下文有关 并且起引出的作用
		cout<<"考上了"<<endl;
		if(score>700&&score<750) //两个区间不能一起写 
		{
			cout<<"清华"<<endl;
		} else if(score>650) {
			cout<<"北大"<<endl;
		} else {
			cout<<"华五"<<endl;
		}
	} else if(score>550) { //不满足第一个条件但满足第二个条件
		cout<<"接受不如意"<<endl;
	} else { //不满足条件
		if(score>500) { //基本上可以随便加,只要满足语法
			cout<<"接受自己的普通"<<endl;
		} else {
			cout<<"再接再励"<<endl;
		}
	}

	return 1;
}
