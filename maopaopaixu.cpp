#include <iostream>
using namespace std;

int main()
{
    int arr[9] = { 4,2,8,0,5,7,1,3,9 };
    cout << "排序前" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    //开始冒泡排序,轮数从0开始,所以从n-1开始 
    for (int i = 0; i < 9 - 1; i++)
    {
        //内层循环对比  次数=元素个数=当前轮数-1
        for (int j = 0; j < 9 - 1 - i; j++)  //最后一位数，已经是最大数了，不需要排序了
        {
        	
            //如果第一个数字，比第二个数字大，交换两个数字
            if (arr[j] > arr[j + 1])
            {
            
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
            }
            //本来想换个思路,用a的,但是a再次循环的时候不会回归0,这个我反复检查都没发现,调试还是不精通 
            
        }
    }

    //排序后结果
    cout << "排序后" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    system("pause");

    return 0;
}
