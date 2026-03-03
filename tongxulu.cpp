#include<iostream>
using namespace std;
#include<string> 
#define MAX 1000//写在上面方便后续改 
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks
{
	struct Person personArray[MAX];//通讯录保存联系人数组 
	int m_Size;//通讯录中人员个数 
};
//菜单界面
void showMenu()
{
	cout<<"$$$$$1.添加联系人$$$$$"<<endl;
	cout<<"$$$$$2.显示联系人$$$$$"<<endl;
	cout<<"$$$$$3.删除联系人$$$$$"<<endl;
	cout<<"$$$$$4.查找联系人$$$$$"<<endl;
	cout<<"$$$$$5.修改联系人$$$$$"<<endl;
	cout<<"$$$$$6.清空联系人$$$$$"<<endl;
	cout<<"$$$$$0.退出联系人$$$$$"<<endl;
	
} 
void addPerson(Addressbooks*abs)
{
	if(abs->m_Size==MAX)//判断通讯录是否已满,如果满了就不再添加
	{
		cout<<"通讯录已满,无法添加!"<<endl;
		return; 
	}
	else
	{
		//添加具体联系人
		
		//姓名
		string name;
		cout<<"请输入姓名:"<<endl;
		cin>> name;
		abs->personArray[abs->m_Size].m_Name=name;
		//性别 
		cout<<"请输入性别:"<<endl;
		cout<<"1---男"<<endl;
		cout<<"2---女"<<endl;
		int sex=0;
		
		
		while(true)//通过死循环使一定得输出1/2 
		{
			cin>>sex; 
		if(sex==1||sex==2)
		{
			abs->personArray[abs->m_Size].m_Sex=sex;
			break;
		}
		cout<<"输入有误,请重新输入"<<endl;
		}
		//年龄
		cout<<"请输入年龄:"<<endl; 
		int age=0;
		cin>>age; 
		abs->personArray[abs->m_Size].m_Age=age;
		//电话
		cout<<"请输入电话:"<<endl;
		string phone; 
		cin>>phone;
		abs->personArray[abs->m_Size].m_Phone=phone;
		
		//地址 
		cout<<"请输入地址:"<<endl;
		string addr; 
		cin>>addr;
		abs->personArray[abs->m_Size].m_Addr=addr;
		
		//更新通讯录人数
		abs->m_Size++; 
		
		cout<<"添加成功"<<endl; 
		
		
	system("pause");
	system("cls");//清屏操作 
	}
}

//显示所有联系人
void showPerson(Addressbooks* abs) //有参数的函数一定要定义 
{
	//判断通讯录中人数是否为0,如果为0,提示记录为空
	//如果不为0,显示记录的联系人信息
	 if(abs->m_Size==0) 
	 {
	 	cout<<"当前记录为空"<<endl; 
	 }
	 else
	 {
	 	for(int i=0;i<abs->m_Size;i++)
	 	{
	 		cout<<"姓名是"<<abs->personArray[i].m_Name<<"\t";
		    cout<<"性别是"<<(abs->personArray[i].m_Sex==1?"男":"女")<<"\t";
		    cout<<"年龄是"<<abs->personArray[i].m_Age<<"\t";
		    cout<<"电话是"<<abs->personArray[i].m_Phone<<"\t";
		    cout<<"地址是"<<abs->personArray[i].m_Addr<<endl;
	   }
	 }
	 system("pause");
	 system("cls");
} 

//删除联系人,先检测联系人是否存在
int isExist(Addressbooks*abs,string name)//检查是否有人 
{
	for(int i=0;i<abs->m_Size;i++)
	{
		if(abs->personArray[i].m_Name==name)
		{
//			cout<<i<<endl;应该是return i;
            return i; 
		}
	
	}
		return -1;//循环结束还是没有找到则是-1 
}

void deletePerson(Addressbooks*abs)//不同函数定义的变量不冲突 
{
	cout<<"请输入你要删除的联系人"<<endl;
	
	string name;
	cin>>name;
	int ret=isExist(abs,name);
	if(ret!=-1)
	{
		for(int i=0;i<abs->m_Size;i++)
		{
		abs->personArray[i]=abs->personArray[i+1];//数据前移 
	    }
		abs->m_Size--; 
	}
	else
	{
		cout<<"查无此人"<<endl;
	}
	system("pause");
	system("cls") ;
}

void findPerson(Addressbooks*abs) 
{
	string name;
	cout<<"请输入你要查找的名字"<<endl;
	cin>>name;
		int ret=isExist(abs,name);
		if(ret!=-1)
		{
			cout<<"姓名是"<<abs->personArray[ret].m_Name<<"\t";
		    cout<<"性别是"<<(abs->personArray[ret].m_Sex==1?"男":"女")<<"\t";
		    cout<<"年龄是"<<abs->personArray[ret].m_Age<<"\t";
		    cout<<"电话是"<<abs->personArray[ret].m_Phone<<"\t";
		    cout<<"地址是"<<abs->personArray[ret].m_Addr<<endl;
		}
		
	
	else
		{
			cout<<"查无此人"<<endl;
		}
		system("pause");
		system("cls");
}
void modifyPerson(Addressbooks*abs)
{
	string name;
	cin>>name;
	int ret=isExist(abs,name);
	if(ret!=-1)
	{
		cout<<"请输入你要修改的姓名"<<endl;
		abs->personArray[ret].m_Name=name;
		
	}
}

void clean(Addressbooks*abs) 
{
	abs->m_Size=0; 
	cout<<"已全部清空"<<endl;
	system("pause");
	system("cls");
}
int main()
{
	Addressbooks abs;//创建结构体变量
	abs.m_Size=0;//初始化通讯录中当前人员个数 
	//菜单调用
	int select=0;
	
	while(true)//让除了0之外都可以继续循环 
	{
		showMenu(); 
		cin>>select;
		switch(select)
	{
		case 1://1.添加联系人
		addPerson(&abs);//往结构体通讯录里面加东西,为了真正修改实参,选择用指针 
		break;
		case 2://2.显示联系人
		showPerson(&abs);
		break;
		case 3://3.删除联系人
//		{
//		cout<<"请输入删除联系人姓名:  "<<endl;
//		string name;
//		cin>>name;
//		if(isExist(&abs,name)==-1) 
//		{
//			cout<<"查无此人"<<endl;
//		
//		}
//		else
//		{
//			cout<<"找到此人"<<endl;
//		}
        deletePerson(&abs);
		break;
	//当case下面的代码过大,要加一个大括号 
		case 4://4.查找联系人
		findPerson(&abs);
		break;
		case 5://5.修改联系人
		//不想写了SOS 
		break;
		case 6://6.清空联系人
		clean(&abs);
		break; 
		case 0://0.退出联系人
		cout<<"欢迎下次使用"<<endl; 
		return 0;
		break;
	}
	}
	
	
return 0;
}
