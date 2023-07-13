# 회전하는 큐 S3
# 자료 구조, 덱
from collections import deque
import sys

input = sys.stdin.readline

n, m = map(int, input().split())  # 큐의 크기 n과 뽑아내려고 하는 수의 개수 m을 입력값으로 받기
position = list(map(int, input().split()))  # 뽑아내려는 수의 위치를 입력값으로 받기
dq = deque([i for i in range(1, n + 1)])  # deque([1, 2, 3,...,n])

count = 0  # 2, 3번 수행하면 카운트 올리기
for i in position:  # 뽑아내려는 수의 위치 하나씩 반복문 돌리기
    while True:  # 뽑을 때까지 계속 돌리기
        if dq[0] == i:  # dq의 첫인덱스가 뽑아내려는 수의 위치와 같다면 1번 수행
            dq.popleft()
            break
        else:
            if (
                dq.index(i) < len(dq) / 2
            ):  # 뽑아내려는 수의 위치 인덱스가 dq의 길이를 반으로 나눈것보다 작을때는 왼쪽으로 움직여야 최소
                while dq[0] != i:  # dq의 첫번째 인덱스가 i와 같아질때까지 반복
                    dq.append(dq.popleft())
                    count += 1
            else:  # 뽑아내려는 수의 위치 인덱스가 dq의 길이를 반으로 나눈것보다 클때는 오른쪽으로 움직여야 최소
                while dq[0] != i:
                    dq.appendleft(dq.pop())
                    count += 1
print(count)
