#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string z;
    cin >> z;
    string s = "";

    for (int i = 0; i < z.length(); ) {
        char ch = z[i];
        if (i + 1 < z.length() && isdigit(z[i + 1])) {
            i++;
            int count = 0;
            while (i < z.length() && isdigit(z[i])) {
                count = count * 10 + (z[i] - '0');
                i++;
            }
            for (int j = 0; j < count; ++j) {
                s += ch;
            }
        } else {
            s += ch;
            i++;
        }
    }

    cout << s << endl;
    return 0;
}
