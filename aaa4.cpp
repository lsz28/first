#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

struct Frog {
    int id;          // 原始索引
    ll x, t, R;      // 位置、舌头长度、可达右端点
    int cnt;         // 吃掉的蚊子数量
};

// 线段树维护区间最大值
vector<ll> tree;

// 更新线段树
void update(int node, int l, int r, int idx, ll value) {
    if (l == r) {
        tree[node] = value;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid)
        update(node * 2, l, mid, idx, value);
    else
        update(node * 2 + 1, mid + 1, r, idx, value);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

// 查询区间[ql,qr]中第一个值 >= p 的下标，没有则返回 -1
int query_first(int node, int l, int r, int ql, int qr, ll p) {
    if (r < ql || l > qr || tree[node] < p)
        return -1;
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    int left_res = query_first(node * 2, l, mid, ql, qr, p);
    if (left_res != -1)
        return left_res;
    return query_first(node * 2 + 1, mid + 1, r, ql, qr, p);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Frog> frog(n);
    for (int i = 0; i < n; ++i) {
        cin >> frog[i].x >> frog[i].t;
        frog[i].id = i;
        frog[i].R = frog[i].x + frog[i].t;
        frog[i].cnt = 0;
    }

    // 按位置排序
    sort(frog.begin(), frog.end(), [](const Frog& a, const Frog& b) {
        return a.x < b.x;
    });

    // 构建线段树
    tree.assign(4 * n, 0);
    for (int i = 0; i < n; ++i) {
        update(1, 0, n - 1, i, frog[i].R);
    }

    // 蚊子集合：按位置存储，pair<位置, 蚊子下标>
    set<pair<ll, int>> mosquitoes;
    vector<ll> b(m); // 蚊子重量

    // 处理每只蚊子
    for (int j = 0; j < m; ++j) {
        ll p, w;
        cin >> p >> w;
        b[j] = w;

        // 插入蚊子
        mosquitoes.insert({p, j});

        // 查找能吃到这只蚊子的青蛙
        // 找到最后一个 x <= p 的青蛙索引
        auto it = upper_bound(frog.begin(), frog.end(), p,
                              [](ll p, const Frog& f) { return p < f.x; });
        int pos = it - frog.begin() - 1;

        if (pos >= 0) {
            // 在线段树中查询[0, pos]中第一个 R >= p 的青蛙
            int idx = query_first(1, 0, n - 1, 0, pos, p);
            if (idx != -1) {
                // 不断喂食这只青蛙，直到没有蚊子可吃
                while (true) {
                    auto itm = mosquitoes.lower_bound({frog[idx].x, -1});
                    if (itm == mosquitoes.end() || itm->first > frog[idx].x + frog[idx].t)
                        break;

                    // 吃掉这只蚊子
                    int j = itm->second;
                    frog[idx].t += b[j];
                    frog[idx].cnt++;
                    frog[idx].R += b[j];

                    // 更新线段树
                    update(1, 0, n - 1, idx, frog[idx].R);

                    // 从集合中删除蚊子
                    mosquitoes.erase(itm);
                }
            }
        }
    }

    // 按原始顺序排序输出
    sort(frog.begin(), frog.end(), [](const Frog& a, const Frog& b) {
        return a.id < b.id;
    });

    for (int i = 0; i < n; ++i) {
        cout << frog[i].cnt << " " << frog[i].t << "\n";
    }

    return 0;
}
