#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string s;
    getline(cin, s);  // 读取整行输入字符串

    // 步骤1：将所有"WUB"替换为空格
    string str_with_spaces;
    for (int i = 0; i < s.size(); ) {
        // 检测当前位置是否为"WUB"
        if (i + 2 < s.size() && s.substr(i, 3) == "WUB") {
            str_with_spaces += ' ';
            i += 3;  // 跳过"WUB"
        } else {
            str_with_spaces += s[i];
            i += 1;
        }
    }

    // 步骤2：提取单词（自动忽略连续空格）
    stringstream ss(str_with_spaces);
    string word;
    vector<string> words;
    while (ss >> word) {  // stringstream会自动分隔单词（忽略空格）
        words.push_back(word);
    }

    // 步骤3：用单个空格连接单词
    string result;
    for (size_t i = 0; i < words.size(); ++i) {
        if (i != 0) result += ' ';
        result += words[i];
    }

    cout << result << endl;
    return 0;
}
