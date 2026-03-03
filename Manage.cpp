#include "Manage.h"

// 全局管理员对象
static Manager manager;
void showSingleRoom(const Room& room) 
{
    cout << left << setw(10) << room.buildingNo 
         << setw(8) << room.roomNo 
         << setw(8) << room.bedCount 
         << setw(8) << room.usedBeds 
         << setw(10) << room.status << endl;
}
void showSingleStudent(const Student& stu) 
{
    cout << left << setw(10) << stu.id 
         << setw(8) << stu.name 
         << setw(15) << stu.connect << endl;
}
// 管理员登录
bool ManagerOperator::loginManager() 
{
    system("cls");
    string inputId, inputPwd;
    cout << "==================== 管理员登录 ====================" << endl;
    cout << "请输入管理员ID：";
    cin >> inputId;
    cout << "请输入管理员密码：";
    cin >> inputPwd;
    
    // 验证管理员账号（使用User基类的id和password）
    if (inputId == manager.id && inputPwd == manager.password) 
	{
        cout << "登录成功！欢迎你，" << manager.name << "！" << endl;
        system("pause");
        showMenu(); // 进入管理员菜单
        return true;
    }
    
    cout << "错误：管理员ID或密码错误！" << endl;
    system("pause");
    return false;
}
void ManagerOperator::changeManagerPassword() 
{
    system("cls");
    cout << "==================== 修改管理员密码 ====================" << endl;
    string oldPwd, newPwd, confirmPwd;

    cout << "请输入原密码：";
    cin >> oldPwd;
    cout << "请输入新密码：";
    cin >> newPwd;
    cout << "请确认新密码：";
    cin >> confirmPwd;

    if (newPwd != confirmPwd) {
        cout << "两次密码不一致！" << endl;
        system("pause");
        return;
    }

    // 调用User基类的changePassword方法
    manager.changePassword(oldPwd, newPwd);
    system("pause");
}


// 添加房间
void ManagerOperator::addRoom() 
{
    system("cls");
    string building, roomNo;
    int bedCount;
    cout << "==================== 添加房间 ====================" << endl;
    cout << "请输入楼栋号（如：1栋）：";
    cin >> building;
    cout << "请输入房间号（如：103）：";
    cin >> roomNo;
    cout << "请输入房间床位数：";
    cin >> bedCount;
    
    // 检查房间是否已存在
    for (const auto& room : roomList) 
	{
        if (room.buildingNo == building && room.roomNo == roomNo) 
		
		{
            cout << "错误：该房间已存在！" << endl;
            system("pause");
            return;
        }
    }
    
    // 添加房间
    roomList.push_back(Room(building, roomNo, bedCount));
    cout << "房间添加成功！" << endl;
    system("pause");
}

// 编辑房间状态
void ManagerOperator::editRoomStatus() 
{
    system("cls");
    string building, roomNo, newStatus;
    cout << "==================== 编辑房间状态 ====================" << endl;
    cout << "请输入楼栋号：";
    cin >> building;
    cout << "请输入房间号：";
    cin >> roomNo;
    
    // 查找房间
    for (auto& room : roomList) 
	{
        if (room.buildingNo == building && room.roomNo == roomNo) 
		{
            cout << "当前状态：" << room.status << endl;
            cout << "请输入新状态（可用/满员/维修中）：";
            cin >> newStatus;
            room.status = newStatus;
            cout << "房间状态修改成功！" << endl;
            system("pause");
            return;
        }
    }
    
    cout << "错误：未找到该房间！" << endl;
    system("pause");
}

// 分配房间
void ManagerOperator::assignRoom() 
{
    system("cls");
    string stuId, building, roomNo;
    cout << "==================== 办理学生入住 ====================" << endl;
    cout << "请输入学生学号：";
    cin >> stuId;
    
    // 检查学生是否存在
    bool stuExist = false;
    for (const auto& stu : studentList) 
	{
        if (stu.id == stuId) {
            stuExist = true;
            break;
        }
    }
    if (!stuExist) 
	{
        cout << "错误：该学生未注册！" << endl;
        system("pause");
        return;
    }
    
    // 检查学生是否已入住
    for (const auto& record : stayRecordList) 
	{
        if (record.studentId == stuId && !record.isCheckedOut) 
		{
            cout << "错误：该学生已入住，无法重复分配！" << endl;
            system("pause");
            return;
        }
    }
    
    cout << "请输入分配的楼栋号：";
    cin >> building;
    cout << "请输入分配的房间号：";
    cin >> roomNo;
    
    // 查找房间并检查是否有空位
    for (auto& room : roomList) 
	{
        if (room.buildingNo == building && room.roomNo == roomNo) 
		{
            if (room.usedBeds >= room.bedCount) 
			{
                cout << "错误：该房间已满员！" << endl;
                system("pause");
                return;
            }
            if (room.status != "可用") 
			{
                cout << "错误：该房间当前状态为「" << room.status << "」，无法入住！" << endl;
                system("pause");
                return;
            }
            
            // 更新房间床位
            room.usedBeds++;
            // 创建入住记录
            StayRecord record(stuId, building + roomNo, DataManager::getCurrentDate());
            stayRecordList.push_back(record);
            
            cout << "入住办理成功！" << endl;
            cout << "学生：" << stuId << " 分配房间：" << building << roomNo << endl;
            system("pause");
            return;
        }
    }
    
    cout << "错误：未找到该房间！" << endl;
    system("pause");
}

// 处理退宿申请
void ManagerOperator::handleCheckout() 
{
    system("cls");
    cout << "==================== 处理退宿申请 ====================" << endl;
    if (checkoutList.empty()) 
	{
        cout << "暂无待处理的退宿申请！" << endl;
        system("pause");
        return;
    }
    
    // 显示所有退宿申请
    for (int i = 0; i < checkoutList.size(); i++) 
	{
        const auto& apply = checkoutList[i];
        cout << i + 1 << ". 学号：" << apply.studentId 
             << " | 申请时间：" << apply.applyTime 
             << " | 状态：" << apply.status 
             << " | 原因：" << apply.reason << endl;
    }
    
    // 选择要处理的申请
    int choice;
    string newStatus;
    cout << "请选择要处理的申请序号（输入0返回）：";
    cin >> choice;
    if (choice == 0) return;
    if (choice < 1 || choice > checkoutList.size()) 
	{
        cout << "错误：无效序号！" << endl;
        system("pause");
        return;
    }
    
    //更新申请状态
    cout << "请输入处理结果（已批准/已拒绝）：";
    cin >> newStatus;
    checkoutList[choice - 1].status = newStatus;
    
    //如果批准退宿，一堆数据要更新
    if (newStatus == "已批准") 
	{
        string stuId = checkoutList[choice - 1].studentId;
        //标记为退宿
        for (auto& record : stayRecordList) 
		{
            if (record.studentId == stuId && !record.isCheckedOut) 
			{
                record.isCheckedOut = true;
                //减少已用床位
                string roomNo = record.roomNo;
                for (auto& room : roomList) 
				{
                    string fullRoomNo = room.buildingNo + room.roomNo;
                    if (fullRoomNo == roomNo) 
					{
                        room.usedBeds--;
                        break;
                    }
                }
                break;
            }
        }
    }
    
    cout << "退宿申请处理成功！" << endl;
    system("pause");
}

// 处理维修申请
void ManagerOperator::handleRepair() 
{
    system("cls");
    cout << "==================== 处理维修申请 ====================" << endl;
    if (repairList.empty()) 
	{
        cout << "暂无待处理的维修申请！" << endl;
        system("pause");
        return;
    }
    
    // 显示所有维修申请
    for (int i = 0; i < repairList.size(); i++) 
	{
        const auto& apply = repairList[i];
        cout << i + 1 << ". 维修单号：" << apply.repairId 
             << " | 申请人：" << apply.studentId 
             << " | 房间：" << apply.roomNo 
             << " | 状态：" << apply.status 
             << " | 故障：" << apply.problem << endl;
    }
    
    // 选择要处理的申请
    int choice;
    string newStatus, repairTime, handler;
    cout << "请选择要处理的申请序号（输入0返回）：";
    cin >> choice;
    if (choice == 0) return;
    if (choice < 1 || choice > repairList.size()) 
	{
        cout << "错误：无效序号！" << endl;
        system("pause");
        return;
    }
    
    // 更新申请状态
    cout << "请输入处理结果（已处理/已拒绝）：";
    cin >> newStatus;
    repairList[choice - 1].status = newStatus;
    
    if (newStatus == "已处理") 
	{
        cout << "请输入维修完成时间（YYYY-MM-DD）：";
        cin >> repairTime;
        cout << "请输入处理人姓名：";
        cin >> handler;
        repairList[choice - 1].repairTime = repairTime;
        repairList[choice - 1].handler = handler;
    }
    
    cout << "维修申请处理成功！" << endl;
    system("pause");
}

// 发布通知
void ManagerOperator::publishNotice() 
{
    system("cls");
    string content;
    cout << "==================== 发布系统通知 ====================" << endl;
    cout << "请输入通知内容：";
    cin.ignore();
    getline(cin, content);
    
    // 创建通知
    Notice notice(content, DataManager::getCurrentDate());
    noticeList.push_back(notice);
    
    cout << "通知发布成功！所有学生均可查看。" << endl;
    system("pause");
}

// 查看所有房间信息
void ManagerOperator::showAllRooms() 
{
    system("cls");
    cout << "==================== 房间分页浏览 ====================" << endl;
    int pageSize = 5; // 每页显示5条
    int currentPage = 1;
    char choice;

    do 
	{
        //
        paginateDisplay<Room>(roomList, pageSize, currentPage, showSingleRoom);

        cout << "操作：[N]下一页 [P]上一页 [Q]退出：";
        cin >> choice;
        if (choice == 'N' || choice == 'n') currentPage++;
        if (choice == 'P' || choice == 'p') currentPage--;
    } while (choice != 'Q' && choice != 'q');
}

// 查看所有学生信息
void ManagerOperator::showAllStudents() 
{
    system("cls");
    cout << "==================== 学生分页浏览 ====================" << endl;
    int pageSize = 5; // 每页显示5条
    int currentPage = 1;
    char choice;

    do 
	{
        // 调用分页工具函数展示学生
        paginateDisplay<Student>(studentList, pageSize, currentPage, showSingleStudent);

        cout << "操作：[N]下一页 [P]上一页 [Q]退出：";
        cin >> choice;
        if (choice == 'N' || choice == 'n') currentPage++;
        if (choice == 'P' || choice == 'p') currentPage--;
    } while (choice != 'Q' && choice != 'q');
}

// 数据统计（房间入住率）
void ManagerOperator::statisticReport() 
{
    system("cls");
    cout << "==================== 入住率统计 ====================" << endl;
    int totalBeds = 0;
    int usedBeds = 0;
    for (const auto& room : roomList) 
	{
        totalBeds += room.bedCount;
        usedBeds += room.usedBeds;
    }
    
    if (totalBeds == 0) 
	{
        cout << "暂无房间数据！" << endl;
    } 
	else 
	{
        double rate = (double)usedBeds / totalBeds * 100;
        cout << "总床位数：" << totalBeds << endl;
        cout << "已用床位数：" << usedBeds << endl;
        cout << "整体入住率：" << fixed << setprecision(2) << rate << "%" << endl;
    }
    cout << "====================================================" << endl;
    system("pause");
}
void ManagerOperator::searchStayRecord() 
{
    system("cls");
    cout << "==================== 住宿记录查找 ====================" << endl;
    string key;
    cout << "请输入查找关键词（学号/房间号）：";
    cin >> key;

    bool found = false;
    cout << "\n查找结果：" << endl;
    cout << "------------------------------------------------------" << endl;
    for (const auto& record : stayRecordList) 
	{
        if (record.studentId == key || record.roomNo == key) 
		{
            found = true;
            cout << "学号：" << record.studentId 
                 << " | 房间：" << record.roomNo 
                 << " | 入住时间：" << record.checkInTime 
                 << " | 退宿状态：" << (record.isCheckedOut ? "已退宿" : "未退宿") << endl;
        }
    }
    if (!found) cout << "未找到匹配的住宿记录！" << endl;
    cout << "------------------------------------------------------" << endl;
    system("pause");
}
//精确搜索（学号）
void ManagerOperator::searchStudentExact() 
{
    system("cls");
    cout << "==================== 学生精确搜索（学号） ====================" << endl;
    string stuId;
    cout << "请输入学生学号：";
    cin >> stuId;

    bool found = false;
    for (const auto& stu : studentList) 
	{
        if (stu.id == stuId) 
		{
            found = true;
            cout << "\n匹配结果：" << endl;
            cout << "学号：" << stu.id << " | 姓名：" << stu.name << " | 联系方式：" << stu.connect << endl;
            break;
        }
    }
    if (!found) cout << "未找到该学号对应的学生！" << endl;
    system("pause");
}
//模糊搜索（姓名）
void ManagerOperator::searchStudentFuzzy() 
{
    system("cls");
    cout << "==================== 学生模糊搜索（姓名） ====================" << endl;
    string nameKey;
    cout << "请输入姓名关键词：";
    cin >> nameKey;

    bool found = false;
    cout << "\n匹配结果：" << endl;
    cout << "------------------------------------------------------" << endl;
    for (const auto& stu : studentList) 
	{
        if (stu.name.find(nameKey) != string::npos) 
		{ // 包含关键词则匹配
            found = true;
            cout << "学号：" << stu.id << " | 姓名：" << stu.name << " | 联系方式：" << stu.connect << endl;
        }
    }
    if (!found) cout << "未找到包含该关键词的学生！" << endl;
    cout << "------------------------------------------------------" << endl;
    system("pause");
}
void ManagerOperator::showMenu() 
{
    int choice;
    while (true) 
	{
        system("cls");
        cout << "==================== 管理员菜单 ====================" << endl;
        cout << "1. 添加房间" << endl;
        cout << "2. 编辑房间状态" << endl;
        cout << "3. 办理学生入住（分配房间）" << endl;
        cout << "4. 处理退宿申请" << endl;
        cout << "5. 处理维修申请" << endl;
        cout << "6. 发布系统通知" << endl;
        cout << "7. 房间分页浏览" << endl;
        cout << "8. 学生分页浏览" << endl;
        cout << "9. 住宿记录查找" << endl;
        cout << "10. 学生精确搜索" << endl;
        cout << "11. 学生模糊搜索" << endl; 
        cout << "12. 修改管理员密码" << endl;
        cout << "13. 数据统计（入住率）" << endl;
        cout << "0. 退出登录" << endl;
        cout << "====================================================" << endl;
        cout << "请选择操作（0-13）：";
        cin >> choice;
        
        switch (choice) 
		{
            case 1:
                ManagerOperator::addRoom();
                break;
            case 2:
                ManagerOperator::editRoomStatus();
                break;
            case 3:
                ManagerOperator::assignRoom();
                break;
            case 4:
                ManagerOperator::handleCheckout();
                break;
            case 5:
                ManagerOperator::handleRepair();
                break;
            case 6:
                ManagerOperator::publishNotice();
                break;
            case 7:
                ManagerOperator::showAllRooms();
                break;
            case 8:
                ManagerOperator::showAllStudents();
                break;
            case 9:
                ManagerOperator::searchStayRecord();
                break;
            case 10:
                ManagerOperator::searchStudentExact();
                break;
            case 11:
                ManagerOperator::searchStudentFuzzy();
                break;
            case 12:
                ManagerOperator::changeManagerPassword();
                break;
            case 13:
                ManagerOperator::statisticReport();
                break;
            case 0:
                DataManager::saveAllData();
                return; // 结束函数，回到上一级登录界面
                
            // 输入错误处理
            default:
                cout << "输入错误！请选择0-13之间的有效选项！" << endl;
                system("pause");
                break;
        }
    }
}
