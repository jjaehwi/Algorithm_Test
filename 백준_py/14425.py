# 문자열 집합 S3
# 자료 구조, 문자열, 해시 / 트리를 이용한 집합과 맵
import sys

input = sys.stdin.readline

N, M = map(int, input().split())
s = set([input() for _ in range(N)])
cnt = 0
for _ in range(M):
    t = input()
    if t in s:
        cnt += 1
print(cnt)
