#include "common.h"
#include "student.h"
#include "Manage.h"

// 清屏+欢迎界面
void showWelcome() 
{
    system("cls");
    cout << "============================================================" << endl;
    cout << "=============== 学生宿舍管理系统============================" << endl;
    cout << "============================================================" << endl;
}

int main() 
{
    // 加载所有数据
    DataManager::loadAllData();
    
    int mainChoice;
    while (true) 
	{
        showWelcome();
        cout << "请选择登录类型：" << endl;
        cout << "1. 学生端" << endl;
        cout << "2. 管理员端" << endl;
        cout << "0. 退出系统" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "请输入选择（0-2）：";
        cin >> mainChoice;
        
        switch (mainChoice) 
		{
            case 1: 
			{
                //先选择注册/登录
                int stuChoice;
                system("cls");
                cout << "==================== 学生端 ====================" << endl;
                cout << "1. 学生注册" << endl;
                cout << "2. 学生登录" << endl;
                cout << "0. 返回上一级" << endl;
                cout << "请选择（0-2）：";
                cin >> stuChoice;
                switch (stuChoice) 
				{
                    case 1: StudentOperator::registerStudent(); break;
                    case 2: StudentOperator::loginStudent(); break;
                    case 0: break;
                    default: 
                        cout << "无效选项！" << endl;
                        system("pause");
                        break;
                }
                break;
            }
            case 2:
                // 管理员端登录
                ManagerOperator::loginManager();
                break;
            case 0:
                // 保存所有数据后退出系统
                DataManager::saveAllData();
                cout << "\n感谢使用学生宿舍管理系统" << endl;
                system("pause");
                return 0;
            default:
                cout << "错误：无效选项！请重新输入" << endl;
                system("pause");
                break;
        }
    }
    return 0;
}
