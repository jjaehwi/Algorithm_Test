# 최대공약수 S1
# 수학, 구현, 정수론, 소수 판정
import sys
input = sys.stdin.readline


def gcd(a, b):
    while b > 0:
        tmp = a % b
        a = b
        b = tmp
    return a


def multiply(lst):
    return eval('*'.join([str(n) for n in lst]))


N = int(input())
N_lst = list(map(int, input().split()))

M = int(input())
M_lst = list(map(int, input().split()))

a = multiply(N_lst)
b = multiply(M_lst)

print('%s' % str(gcd(a, b))[-9:])
