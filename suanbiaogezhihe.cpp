#include <iostream>
#include<string> 
using namespace std;

int main()
{
    //二维数组案例-考试成绩统计
    //1、创建二维数组
    int scores[3][3] =
    {
        {100,100,100},
        {90,50,100},
        {60,70,80}
    };

    //2、统计每个人的总和分数
    for (int i = 0; i < 3; i++)
    {
    	string name[3]={"张三","李四","王五"};//很少用,注意 
        int sum = 0; //统计分数总和不变
        for (int j = 0; j < 3; j++)
        {
            sum += scores[i][j];//赋值运算符,可以用来做加减  很少用,注意 
            //cout << scores[i][j] << " ";
        }
        cout <<name[i]<< "的总分为：" << sum << endl;
    }

    system("pause");

    return 0;
}
