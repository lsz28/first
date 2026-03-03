#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int n = s.size();
    long long count = 0;  // 避免大数溢出

    // 遍历所有'@'的位置
    for (int at_pos = 0; at_pos < n; ++at_pos) {
        if (s[at_pos] != '@') continue;

        // 1. 统计前缀的合法子串数（0 ~ at_pos-1）
        long long prefix_valid = 0;
        if (at_pos == 0) continue;  // 前缀不能为空
        if (!isalpha(s[0])) continue;  // 前缀必须以字母开头

        // 遍历前缀的每个位置，统计连续合法的子串数
        for (int i = 0; i < at_pos; ++i) {
            char c = s[i];
            // 前缀合法字符：字母、数字、_、.
            if (!isalnum(c) && c != '_' && c != '.') {
                break;  // 遇到非法字符，后续前缀无效
            }
            prefix_valid++;  // 每一个合法位置对应一个前缀（从0到i）
        }
        if (prefix_valid == 0) continue;

        // 2. 遍历'@'右侧所有'.'的位置
        for (int dot_pos = at_pos + 1; dot_pos < n; ++dot_pos) {
            if (s[dot_pos] != '.') continue;

            // 3. 验证域名前缀（at_pos+1 ~ dot_pos-1）：纯字母/数字，非空
            bool domain_ok = true;
            int domain_len = dot_pos - at_pos - 1;
            if (domain_len < 1) {
                domain_ok = false;
            } else {
                for (int i = at_pos + 1; i < dot_pos; ++i) {
                    if (!isalnum(s[i])) {
                        domain_ok = false;
                        break;
                    }
                }
            }
            if (!domain_ok) continue;

            // 4. 验证后缀（dot_pos+1 ~ n-1）：纯字母，非空
            bool suffix_ok = true;
            int suffix_len = n - dot_pos - 1;
            if (suffix_len < 1) {
                suffix_ok = false;
            } else {
                for (int i = dot_pos + 1; i < n; ++i) {
                    if (!isalpha(s[i])) {
                        suffix_ok = false;
                        break;
                    }
                }
            }
            if (!suffix_ok) continue;

            // 累加合法前缀数
            count += prefix_valid;
        }
    }

    cout << count << endl;
    return 0;
}
