# 창문 닫기 S5
import sys

N = int(sys.stdin.readline())
result = 0
x = 1
while x * x <= N:
    x += 1
    result += 1
print(result)
