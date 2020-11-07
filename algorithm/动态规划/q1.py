#!/usr/bin/env python3
# _*_ coding:utf-8 _*_

'''
n阶台阶，青蛙每次只能跳一阶或两阶，有多少种跳法
'''


def recursion(n):
    if (n > 2):
        return recursion(n-1) + recursion(n-2)
    else:
        return n


def DP(n):
    i = 1
    g = 1
    f = 1
    while(i < n):
        g = g+f
        f = g-f
        i += 1
    return g


if __name__ == '__main__':

    s = DP(60)
    print(s)
