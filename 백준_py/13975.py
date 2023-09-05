# 파일 합치기3 G4
# 자료구조, 그리디, 우선순위 큐
import sys

input = sys.stdin.readline
import heapq

t = int(input())

for _ in range(t):
    n = int(input())
    lst = list(map(int, input().split()))
    ans = 0
    q = []
    for i in lst:
        heapq.heappush(q, i)
    while len(q) > 1:
        a = heapq.heappop(q)
        b = heapq.heappop(q)
        ans += a + b
        heapq.heappush(q, a + b)
    print(ans)
