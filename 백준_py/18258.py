# 큐 2 S4
# 자료구조, 큐
# list 사용하면 안되고 deque 사용해야함.
import sys
from collections import deque

n = int(input())
queue = deque([])
for i in range(n):
    com = sys.stdin.readline().split()
    if com[0] == "push":
        queue.append(com[1])
    elif com[0] == "pop":
        if len(queue) == 0:
            print(-1)
        else:
            print(queue.popleft())
    elif com[0] == "size":
        print(len(queue))
    elif com[0] == "empty":
        if len(queue) == 0:
            print(1)
        else:
            print(0)
    elif com[0] == "front":
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[0])
    elif com[0] == "back":
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[-1])
