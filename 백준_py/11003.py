# 최솟값 찾기 P5
# 자료구조, 우선순위 큐, 덱
import sys
from collections import deque

input = sys.stdin.readline
N, L = map(int, input().split())
num = list(map(int, input().split()))
##최솟값을 구할 곳
temp = deque([])

for i in range(N):
    ## 슬라이딩 윈도우 범위를 벗어나는 원소 삭제(당연히 맨 앞의 원소)
    if temp and temp[0][0] <= i - L:
        temp.popleft()

    ## 들어올 원소가 기존의 원소보다 작으면 기존원소 삭제
    while len(temp) >= 1 and num[i] < temp[-1][1]:
        temp.pop()

    ## 들어올 원소 추가
    temp.append((i, num[i]))

    print(temp[0][1], end=" ")
