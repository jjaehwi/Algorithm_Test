# 듣보잡 S4
# 문자열, 정렬
import sys

input = sys.stdin.readline

n, m = map(int, input().split())

arr1 = []
arr2 = []
for i in range(n):
    x = input()
    arr1.append(x)
for i in range(m):
    y = input()
    arr2.append(y)

answer = list(set(arr1) & set(arr2))
answer.sort()
print(len(answer))
print("".join(answer), end="")
