# 재귀의 귀재 B2
# 구현, 재귀
import sys

input = sys.stdin.readline


def recursion(s, l, r):
    global cnt  # 함수 내에서 전역 변수로 cnt를 활용하기 위해 global로 명시해준다.
    cnt += 1

    if l >= r:
        return 1
    elif s[l] != s[r]:
        return 0
    else:
        return recursion(s, l + 1, r - 1)


def isPalindrome(s):
    return recursion(s, 0, len(s) - 1)


for _ in range(int(input())):
    cnt = 0
    print(isPalindrome(input().rstrip()), cnt)
