#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
    int t, type, w;
    Event(int t_, int type_, int w_) : t(t_), type(type_), w(w_) {}
};

bool cmp(const Event& a, const Event& b) {
    if (a.t != b.t) return a.t < b.t;
    if (a.type != b.type) return a.type > b.type;
    return a.w < b.w;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> key_box(N);
    vector<int> pos(N + 1);
    for (int i = 0; i < N; ++i) {
        key_box[i] = i + 1;
        pos[i + 1] = i;
    }
    vector<Event> events;
    for (int i = 0; i < K; ++i) {
        int w, s, c;
        cin >> w >> s >> c;
        events.emplace_back(s, 0, w);
        events.emplace_back(s + c, 1, w);
    }
    sort(events.begin(), events.end(), cmp);
    for (const auto& e : events) {
        if (e.type == 0) {
            key_box[pos[e.w]] = 0;
        } else {
            for (int i = 0; i < N; ++i) {
                if (key_box[i] == 0) {
                    key_box[i] = e.w;
                    pos[e.w] = i;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << key_box[i] << (i == N - 1 ? "\n" : " ");
    }
    return 0;
}
