# 최소공배수 B1
import sys

T = int(input())

for i in range(T):
    a, b = map(int, sys.stdin.readline().split())
    aa, bb = a, b

    while a % b != 0:
        a, b = b, a % b

    print(aa * bb // b)
