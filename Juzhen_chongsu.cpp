#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;

    // 读取原矩阵（存储为一维数组，直接按行优先顺序读取）
    vector<int> linear(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> linear[i * m + j];
        }
    }

    // 填充新矩阵并输出
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < q; ++j) {
            // 新矩阵(i,j)对应的一维数组索引是 i*q + j
            if (j > 0) cout << " ";
            cout << linear[i * q + j];
        }
        cout << endl;
    }

    return 0;
}

