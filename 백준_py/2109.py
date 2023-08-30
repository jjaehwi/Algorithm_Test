# 순회공연 G3
# 그리디, 정렬, 우선순위 큐
import heapq

n = int(input())
lst = []
for i in range(n):
    lst.append(list(map(int, input().split())))

lst.sort(key=lambda x: (x[1]))
p_list = []
for i in lst:
    heapq.heappush(p_list, i[0])
    if len(p_list) > i[1]:
        heapq.heappop(p_list)

print(sum(p_list))
