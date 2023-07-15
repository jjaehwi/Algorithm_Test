# 단어 정렬 S5
# 문자열, 정렬
import sys

n = int(sys.stdin.readline())
lst = []

for i in range(n):
    lst.append(sys.stdin.readline().strip())
set_lst = set(lst)
lst = list(set_lst)
lst.sort()
lst.sort(key=len)

for i in lst:
    print(i)
