# 생일 S5
# 구현, 문자열, 정렬
import sys
input = sys.stdin.readline

lst = []
for _ in range(int(input())):
    n, d, m, y = input().rstrip().split()
    d, m, y = map(int, (d, m, y))
    lst.append((y, m, d, n))
lst.sort()
print(lst[-1][3])
print(lst[0][3])
