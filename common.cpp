#include "common.h"
#include"student.h"
#include"Manage.h" 

// 全局容器初始化
vector<Room> roomList;
vector<StayRecord> stayRecordList;
vector<CheckoutApply> checkoutList;
vector<RepairApply> repairList;
vector<Notice> noticeList;
vector<Student> studentList;

// 获取当前日期（用了时间戳）
string DataManager::getCurrentDate() 
{
    time_t t = time(NULL);
    tm* localTime = localtime(&t);
    ostringstream oss;//自定义,使转为字符串更方便 
    oss << 1900 + localTime->tm_year << "-" 
        << setw(2) << setfill('0') << 1 + localTime->tm_mon << "-" 
        << setw(2) << setfill('0') << localTime->tm_mday;
    return oss.str();
}

// 加载所有数据
void DataManager::loadAllData() 
{
    loadRoomData();
    loadStudentData();
    loadStayRecordData();
    loadCheckoutApplyData();
    loadRepairApplyData();
    // 初始化测试数据（如果文件为空）
    if (roomList.empty()) 
	{
        roomList.push_back(Room("1栋", "101", 4));
        roomList.push_back(Room("1栋", "102", 4));
    }
    if (studentList.empty()) 
	{
       studentList.push_back(Student("2025002", "李四", "654321", "13800138002"));
       studentList.push_back(Student("2025001", "张三", "123456", "13800138001"));
//       studentList.push_back(Student("2025003", "", "", ""));
//       studentList.push_back(Student("2025004", "", "", ""));
//       studentList.push_back(Student("2025005", "", "", ""));
    }
    cout << "数据加载完成！" << endl;
}

// 保存所有数据
void DataManager::saveAllData() 
{
    saveRoomData();
    saveStudentData();
    saveStayRecordData();
    saveCheckoutApplyData();
    saveRepairApplyData();
    cout << "所有数据已保存到文件！" << endl;
}

// 保存房间数据到txt
void DataManager::saveRoomData() 
{
    ofstream fout("room_data.txt");
    if (!fout) 
	{
        cout << "错误：无法打开room_data.txt文件进行写入！" << endl;
        return;
    }
    for (const auto& room : roomList) 
	{
        fout << room.buildingNo << "," 
             << room.roomNo << "," 
             << room.bedCount << "," 
             << room.usedBeds << "," 
             << room.status << endl;
    }
    fout.close();
}

//从文件加载房间数据
void DataManager::loadRoomData() 
{
    ifstream fin("room_data.txt");
    if (!fin) 
	{
        cout << "提示：未找到room_data.txt，将使用默认数据！" << endl;
        return;
    }
    string line;
    while (getline(fin, line)) 
	{
		//因为房间有5个信息 
        size_t pos1 = line.find(",");//找逗号的位置,根据逗号切割数据 
        size_t pos2 = line.find(",", pos1 + 1);
        size_t pos3 = line.find(",", pos2 + 1);
        size_t pos4 = line.find(",", pos3 + 1);
        
        string building = line.substr(0, pos1);
        string roomNo = line.substr(pos1 + 1, pos2 - pos1 - 1);
        int bedCount = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
        int usedBeds = stoi(line.substr(pos3 + 1, pos4 - pos3 - 1));
        string status = line.substr(pos4 + 1);
        
        Room room(building, roomNo, bedCount);
        room.usedBeds = usedBeds;
        room.status = status;
        roomList.push_back(room);
    }
    fin.close();
}

// 保存学生数据到文件（student_data.txt）
void DataManager::saveStudentData() 
{
    ofstream fout("student_data.txt");
    if (!fout) 
	{
        cout << "错误：无法打开student_data.txt文件进行写入！" << endl;
        return;
    }
    for (const auto& stu : studentList) 
	{
        fout << stu.id << "," 
             << stu.name << "," 
             << stu.password << "," 
             << stu.connect << endl;
    }
    fout.close();
}

// 加载学生数据从文件
void DataManager::loadStudentData() 
{
    ifstream fin("student_data.txt");
    if (!fin) 
	{
        cout << "提示：未找到student_data.txt，将使用默认数据！" << endl;
        return;
    }
    string line;
    while (getline(fin, line)) 
	{
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);
        size_t pos3 = line.find(",", pos2 + 1);
        
        string id = line.substr(0, pos1);
        string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string pwd = line.substr(pos2 + 1, pos3 - pos2 - 1);
        string connect = line.substr(pos3 + 1);
        
        studentList.push_back(Student(id, name, pwd, connect));
    }
    fin.close();
}

// 保存住宿记录到文件（stay_record.txt）
void DataManager::saveStayRecordData() 
{
    ofstream fout("stay_record.txt");
    if (!fout) 
	{
        cout << "错误：无法打开stay_record.txt文件进行写入！" << endl;
        return;
    }
    for (const auto& record : stayRecordList) 
	{
        fout << record.studentId << "," 
             << record.roomNo << "," 
             << record.checkInTime << "," 
             << (record.isCheckedOut ? "1" : "0") << endl;
    }
    fout.close();
}

// 加载住宿记录从文件
void DataManager::loadStayRecordData() 
{
    ifstream fin("stay_record.txt");
    if (!fin) 
	{
        cout << "提示：未找到stay_record.txt，暂无住宿记录！" << endl;
        return;
    }
    string line;
    while (getline(fin, line)) 
	{
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);
        size_t pos3 = line.find(",", pos2 + 1);
        
        string sid = line.substr(0, pos1);
        string rNo = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string time = line.substr(pos2 + 1, pos3 - pos2 - 1);
        bool isOut = (line.substr(pos3 + 1) == "1");
        
        StayRecord record(sid, rNo, time);
        record.isCheckedOut = isOut;
        stayRecordList.push_back(record);
    }
    fin.close();
}

// 保存退宿申请到文件（checkout_apply.txt）
void DataManager::saveCheckoutApplyData() 
{
    ofstream fout("checkout_apply.txt");
    if (!fout) 
	{
        cout << "错误：无法打开checkout_apply.txt文件进行写入！" << endl;
        return;
    }
    for (const auto& apply : checkoutList) 
	{
        fout << apply.studentId << "," 
             << apply.applyTime << "," 
             << apply.reason << "," 
             << apply.status << endl;
    }
    fout.close();
}

// 加载退宿申请
void DataManager::loadCheckoutApplyData() 
{
    ifstream fin("checkout_apply.txt");
    if (!fin) 
	{
        cout << "提示：未找到checkout_apply.txt，暂无退宿申请！" << endl;
        return;
    }
    string line;
    while (getline(fin, line)) 
	{
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);
        size_t pos3 = line.find(",", pos2 + 1);
        
        string sid = line.substr(0, pos1);
        string time = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string res = line.substr(pos2 + 1, pos3 - pos2 - 1);
        string stat = line.substr(pos3 + 1);
        
        checkoutList.push_back(CheckoutApply(sid, time, stat, res));
    }
    fin.close();
}

// 保存维修申请到文件（repair_apply.txt）
void DataManager::saveRepairApplyData() 
{
    ofstream fout("repair_apply.txt");
    if (!fout) 
	{
        cout << "错误：无法打开repair_apply.txt文件进行写入！" << endl;
        return;
    }
    for (const auto& apply : repairList) 
	{
        fout << apply.repairId << "," 
             << apply.studentId << "," 
             << apply.applyTime << "," 
             << apply.problem << "," 
             << apply.roomNo << "," 
             << apply.status << "," 
             << apply.repairTime << "," 
             << apply.handler << endl;
    }
    fout.close();
}

// 加载维修申请
void DataManager::loadRepairApplyData() 
{
    ifstream fin("repair_apply.txt");
    if (!fin) {
        cout << "提示：未找到repair_apply.txt，暂无维修申请！" << endl;
        return;
    }
    string line;
    while (getline(fin, line)) 
	{
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);
        size_t pos3 = line.find(",", pos2 + 1);
        size_t pos4 = line.find(",", pos3 + 1);
        size_t pos5 = line.find(",", pos4 + 1);
        size_t pos6 = line.find(",", pos5 + 1);
        size_t pos7 = line.find(",", pos6 + 1);
        
        string rId = line.substr(0, pos1);
        string sid = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string time = line.substr(pos2 + 1, pos3 - pos2 - 1);
        string prob = line.substr(pos3 + 1, pos4 - pos3 - 1);
        string rNo = line.substr(pos4 + 1, pos5 - pos4 - 1);
        string stat = line.substr(pos5 + 1, pos6 - pos5 - 1);
        string rTime = line.substr(pos6 + 1, pos7 - pos6 - 1);
        string handler = line.substr(pos7 + 1);
        
        RepairApply apply(sid, time, stat, rNo, prob);
        apply.repairId = rId;
        apply.repairTime = rTime;
        apply.handler = handler;
        repairList.push_back(apply);
    }
    fin.close();
}
