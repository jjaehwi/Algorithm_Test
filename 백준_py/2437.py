# 저울 G2
# 그리디, 정렬
import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
arr.sort()

target = 1

for num in arr:
    if target < num:
        break

    target += num

print(target)
