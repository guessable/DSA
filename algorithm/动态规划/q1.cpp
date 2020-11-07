/*
 * n阶台阶，青蛙每次只能跳一阶或两阶，有多少种跳法
 */

#include <iostream>

using namespace std;

// 递归解法(指数级)
long long recursion(long long n) {
    return (n > 2) ? recursion(n - 1) + recursion(n - 2) : n;
}

// 动态规划(线性级)
long long DP(long long n) {
    long long i = 0;
    long long f = 1;
    long long g = 1;

    while(++i < n) {
        g = g + f;
        f = g - f;
    }

    return g;
}

int main() {
    cout << "台阶数：";
    long long n;
    cin >> n;
    long long sum = DP(n);
    cout << "跳法有：" << sum << "种" << endl;
}
