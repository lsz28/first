#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
#include <cmath>

using namespace std;

// 左右手字符集（小写）
const string LEFT_HAND = "qwertasdfgzxcvb";
const string RIGHT_HAND = "yuiophjklnm";

// 判断字符对应的手（1=左手，2=右手）
int getHand(char c) {
    char lowerC = tolower(c);
    if (LEFT_HAND.find(lowerC) != string::npos) {
        return 1;
    } else if (RIGHT_HAND.find(lowerC) != string::npos) {
        return 2;
    }
    return 0; // 输入合法字符时不会触发
}

// 计算单词首次输入的耗时（单位：秒）
double calcFirstTime(const string &word) {
    if (word.empty()) return 0.0;
    double time = 0.2; // 第一个字符耗时
    int prevHand = getHand(word[0]);
    for (size_t i = 1; i < word.size(); ++i) {
        int currHand = getHand(word[i]);
        time += (currHand == prevHand) ? 0.4 : 0.2;
        prevHand = currHand;
    }
    return time;
}

int main() {
    int N;
    cin >> N;
    unordered_map<string, double> wordTime; // 记录单词首次输入耗时
    double total = 0.0;

    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        if (wordTime.count(word)) {
            // 重复输入，耗时减半
            total += wordTime[word] / 2.0;
        } else {
            // 首次输入，计算并记录耗时
            double firstTime = calcFirstTime(word);
            wordTime[word] = firstTime;
            total += firstTime;
        }
    }

    // 转换为十分之一秒（四舍五入）
    cout << static_cast<int>(round(total * 10)) << endl;
    return 0;
}
