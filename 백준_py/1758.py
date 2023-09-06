# 알바생 강호 S4
# 그리디, 정렬
import sys

n = int(sys.stdin.readline())

li = []
for i in range(n):
    li.append(int(sys.stdin.readline()))

li.sort(reverse=True)

total = 0
for i in range(n):
    ans = li[i] - i
    if ans < 0:
        break
    total += li[i] - i

print(total)
