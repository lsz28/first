#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 计算最大公约数（欧几里得算法）
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 计算10的n次方
long long pow10(int n) {
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result *= 10;
    }
    return result;
}

void decimal_to_fraction(char *s) {
    char *dot = strchr(s, '.');
    char *left = strchr(s, '(');
    char *right = strchr(s, ')');
    
    long long numerator = 0, denominator = 1;
    int non_cycle_len = 0, cycle_len = 0;

    // 提取非循环部分和循环部分
    if (left == NULL) { // 有限小数
        non_cycle_len = strlen(dot + 1);
        numerator = atoll(dot + 1);
        denominator = pow10(non_cycle_len);
    } else { // 循环小数
        non_cycle_len = left - (dot + 1);
        if (non_cycle_len > 0) {
            char non_cycle[10] = {0};
            strncpy(non_cycle, dot + 1, non_cycle_len);
            numerator = atoll(non_cycle);
            denominator = pow10(non_cycle_len);
        }
        // 提取循环部分
        cycle_len = right - left - 1;
        char cycle[10] = {0};
        strncpy(cycle, left + 1, cycle_len);
        long long cycle_num = atoll(cycle);
        // 计算循环部分对应的分数
        long long cycle_den = pow10(cycle_len) - 1;
        // 通分相加：a/b + c/(d*b) = (a*d + c)/(b*d)
        numerator = numerator * cycle_den + cycle_num;
        denominator *= cycle_den;
    }
    // 约分
    long long g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
    printf("%lld/%lld\n", numerator, denominator);
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); // 吸收换行符
    for (int i = 0; i < N; i++) {
        char s[20];
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = '\0'; // 去掉换行符
        decimal_to_fraction(s);
    }
    return 0;
}
