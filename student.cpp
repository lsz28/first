#include "student.h"

//注册
bool StudentOperator::registerStudent() 
{
    system("cls");
    string id, name, pwd, pwdConfirm, conn;
    cout << "==================== 学生注册 ====================" << endl;
    cout << "请输入学号（如：2025003）：";
    cin >> id;
    
    // 检查学号是否已存在
    for (const auto& stu : studentList) 
	{
        if (stu.id == id) 
		{
            cout << "错误：该学号已注册！" << endl;
            system("pause");
            return false;
        }
    }
    
    cout << "请输入姓名：";
    cin >> name;
    cout << "请输入密码：";
    cin >> pwd;
    cout << "请确认密码：";
    cin >> pwdConfirm;
    
    if (pwd != pwdConfirm) 
	{
        cout << "错误：两次密码不一致！" << endl;
        system("pause");
        return false;
    }
    
    cout << "请输入联系方式（电话）：";
    cin >> conn;
    
    // 添加到学生列表
    studentList.push_back(Student(id, name, pwd, conn));
    cout << "注册成功！请记住你的学号和密码。" << endl;
    system("pause");
    return true;
}
//登录 
bool StudentOperator::loginStudent() 
{
    system("cls");
    string id, pwd;
    cout << "==================== 学生登录 ====================" << endl;
    cout << "请输入学号：";
    cin >> id;
    cout << "请输入密码：";
    cin >> pwd;
    
    // 验证账号密码
    for (const auto& stu : studentList) 
	{
        if (stu.id == id && stu.password == pwd) 
		{
            cout << "登录成功！欢迎你，" << stu.name << "同学！" << endl;
            system("pause");
            showMenu(id); //登录后进入学生菜单
            return true;
        }
    }
    
    cout << "错误：学号或密码错误！" << endl;
    system("pause");
    return false;
}
//学生端修改密码
void StudentOperator::changeStudentPassword(string stuId) 
{
    system("cls");
    cout << "==================== 修改个人密码 ====================" << endl;
    string oldPwd, newPwd, confirmPwd;

    // 找到当前学生对象
    Student* currentStu = nullptr;
    for (auto& stu : studentList) 
	{
        if (stu.id == stuId) {
            currentStu = &stu;
            break;
        }
    }
    if (!currentStu) 
	{
        cout << "学生信息不存在！" << endl;
        system("pause");
        return;
    }

    cout << "请输入原密码：";
    cin >> oldPwd;
    cout << "请输入新密码：";
    cin >> newPwd;
    cout << "请确认新密码：";
    cin >> confirmPwd;

    if (newPwd != confirmPwd) 
	{
        cout << "两次密码不一致！" << endl;
        system("pause");
        return;
    }

    // 调用User基类的changePassword方法
    currentStu->changePassword(oldPwd, newPwd);
    system("pause");
}

// 查看个人信息
void StudentOperator::showPersonalInfo(string stuId) 
{
    system("cls");
    cout << "==================== 个人信息 ====================" << endl;
    for (const auto& stu : studentList) 
	{
        if (stu.id == stuId) 
		{
            cout << "学号：" << stu.id << endl;
            cout << "姓名：" << stu.name << endl;
            cout << "联系方式：" << stu.connect << endl;
            break;
        }
    }
    cout << "==================================================" << endl;
    system("pause");
}

// 申请退宿
void StudentOperator::applyCheckout(string stuId) 
{
    system("cls");
    string reason;
    cout << "==================== 退宿申请 ====================" << endl;
    cout << "请输入退宿原因：";
    cin.ignore(); // 忽略换行符
    getline(cin, reason);
    
    // 创建退宿申请
    CheckoutApply apply(stuId, DataManager::getCurrentDate(), "待处理", reason);
    checkoutList.push_back(apply);
    
    cout << "退宿申请提交成功！请等待管理员审核。" << endl;
    system("pause");
}

// 申请维修
void StudentOperator::applyRepair(string stuId) 
{
    system("cls");
    string roomNo, problem;
    cout << "==================== 维修申请 ====================" << endl;
    cout << "请输入报修房间号（如：1栋101）：";
    cin >> roomNo;
    cout << "请输入故障描述：";
    cin.ignore();
    getline(cin, problem);
    
    // 创建维修申请
    RepairApply apply(stuId, DataManager::getCurrentDate(), "待处理", roomNo, problem);
    repairList.push_back(apply);
    
    cout << "维修申请提交成功！维修单号：" << apply.repairId << endl;
    cout << "请等待管理员处理。" << endl;
    system("pause");
}

// 查看通知
void StudentOperator::showNotices(string stuId) 
{
    system("cls");
    cout << "==================== 我的通知 ====================" << endl;
    // 查找当前学生的通知
    if (noticeList.empty()) 
	{
        cout << "暂无通知！" << endl;
    } else 
	{
        for (int i = 0; i < noticeList.size(); i++) 
		{
			//这里是因为数组由0开始,但是序号一般是1开始 
            cout << i + 1 << ". [" << noticeList[i].time << "] " << noticeList[i].content << endl;
        }
    }
    cout << "==================================================" << endl;
    system("pause");
}

// 查看本人住宿记录
void StudentOperator::showMyStayRecord(string stuId) 
{
    system("cls");
    cout << "==================== 我的住宿记录 ====================" << endl;
    bool hasRecord = false;
    for (const auto& record : stayRecordList) 
	{
        if (record.studentId == stuId) 
		{
            hasRecord = true;
            cout << "房间号：" << record.roomNo << endl;
            cout << "入住时间：" << record.checkInTime << endl;
            cout << "是否退宿：" << (record.isCheckedOut ? "是" : "否") << endl;
            cout << "--------------------------------------------------" << endl;
        }
    }
    if (!hasRecord) 
	{
        cout << "暂无住宿记录！" << endl;
    }
    cout << "====================================================" << endl;
    system("pause");
}
//展现学生菜单 
void StudentOperator::showMenu(string stuId) 
{
    int choice;
    while (true) 
	{
        system("cls");
        cout << "==================== 学生菜单 ====================" << endl;
        cout << "1. 查看个人信息" << endl;
        cout << "2. 查看我的住宿记录" << endl;
        cout << "3. 申请退宿" << endl;
        cout << "4. 申请维修" << endl;
        cout << "5. 查看通知" << endl;
        cout << "6. 修改个人密码" << endl; // 新增：扩展功能
        cout << "0. 退出登录" << endl;
        cout << "==================================================" << endl;
        cout << "请选择操作（0-6）：";
        cin >> choice;
        
        switch (choice) 
		{
            case 1:
                StudentOperator::showPersonalInfo(stuId);
                break;
            case 2:
                //查看我的住宿记录
                StudentOperator::showMyStayRecord(stuId);
                break;
            case 3:
                //申请退宿
                StudentOperator::applyCheckout(stuId);
                break;
            case 4:
                StudentOperator::applyRepair(stuId);
                break;
            case 5:
                StudentOperator::showNotices(stuId);
                break;
            case 6:
                StudentOperator::changeStudentPassword(stuId);
                break;
            case 0:
                // 退出登录：保存数据 + 结束循环
                DataManager::saveAllData();// 保存学生数据
                system("pause");
                return; // 直接退出当前函数，回到上一级界面
            default:
                cout << "输入错误！请选择0-6之间的选项" << endl;
                system("pause");
                break;
        }
    }
}
