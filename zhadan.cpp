#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);  // 关闭同步，加速 cin/cout
    cin.tie(nullptr);             // 解除 cin 和 cout 绑定

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);  // 用 vector 存储矩阵，灵活且安全
        vector<int> wall_rows, wall_cols;  // 存储所有墙的行号和列号

        // 读取矩阵并收集墙的位置
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '*') {
                    wall_rows.push_back(i);
                    wall_cols.push_back(j);
                }
            }
        }

        int wall_cnt = wall_rows.size();
        if (wall_cnt == 0) {  // 无墙时直接满足条件
            cout << "YES\n";
            continue;
        }

        // 候选位置：取第一个墙的行 r 和列 c（所有墙必须在 r 行或 c 列）
        int r = wall_rows[0];
        int c = wall_cols[0];
        bool can_destroy = true;

        // 验证所有墙是否在 r 行或 c 列
        for (int i = 0; i < wall_cnt; ++i) {
            if (wall_rows[i] != r && wall_cols[i] != c) {
                can_destroy = false;
                break;
            }
        }

        cout << (can_destroy ? "YES" : "NO") << '\n';
    }

    return 0;
}
