# 컵라면 G2
# 자료 구조, 그리디, 우선순위 큐
import heapq
import sys

read = sys.stdin.readline

N = int(read().strip("\n"))

problems = []

for _ in range(N):
    deadline, cup_noodle = map(int, read().strip("\n").split())
    problems.append((deadline, cup_noodle))

problems.sort()

queue = []

for deadline, cup_noodle in problems:
    heapq.heappush(queue, cup_noodle)
    if deadline < len(queue):
        heapq.heappop(queue)

print(sum(queue))
