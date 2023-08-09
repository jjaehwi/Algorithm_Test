# 통나무 건너뛰기 S1
# 그리디
from sys import stdin

for _ in range(int(stdin.readline())):
    n = int(stdin.readline())
    arr = list(map(int, stdin.readline().split()))
    arr.sort()
    res = 0
    for i in range(2, n):
        res = max(res, abs(arr[i] - arr[i - 2]))
    print(res)
