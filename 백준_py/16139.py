# 인간-컴퓨터 상호작용 S1
# 누적합
import sys
input = sys.stdin.readline

s = input().rstrip()
arr = [[0]*26]
arr[0][ord(s[0])-97] = 1
for i in range(1, len(s)):
    arr.append(arr[-1][:])
    arr[i][ord(s[i])-97] += 1

for _ in range(int(input())):
    c, start, end = list(input().split())
    start, end = map(int, [start, end])
    if start == 0:
        print(arr[end][ord(c)-97])
    else:
        print(arr[end][ord(c)-97]-arr[start-1][ord(c)-97])
