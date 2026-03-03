#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        long long minX, maxX;
        cin >> N >> minX >> maxX;
        
        int even_out = 0, odd_out = 1;
        for (int i = 0; i < N; ++i) {
            long long w, b;
            cin >> w >> b;
            int w_p = w % 2, b_p = b % 2;
            int new_even = (w_p * even_out + b_p) % 2;
            int new_odd = (w_p * odd_out + b_p) % 2;
            even_out = new_even;
            odd_out = new_odd;
        }
        
        long long total = maxX - minX + 1;
        long long even_x = (total + (1 - (minX % 2))) / 2;
        long long odd_x = total - even_x;
        
        long long non_spam = 0, spam = 0;
        if (even_out == 0) non_spam += even_x;
        else spam += even_x;
        if (odd_out == 0) non_spam += odd_x;
        else spam += odd_x;
        
        cout << non_spam << " " << spam << endl;
    }
    return 0;
}
