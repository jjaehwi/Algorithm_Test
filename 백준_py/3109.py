# 빵집 G2
# 그리디, 그래프 탐색, DFS
import sys

input = sys.stdin.readline
answer = 0


def dfs(x, y):
    if y == C - 1:
        return True
    for dx in [-1, 0, 1]:
        ax = x + dx
        ay = y + 1
        if 0 <= ax < R and 0 <= ay < C:
            if board[ax][ay] != "x" and visited[ax][ay] == -1:
                visited[ax][ay] = 1
                if dfs(ax, ay):
                    return True
    return False


R, C = map(int, input().split())
visited = [[-1 for _ in range(C)] for _ in range(R)]
board = [list(input().strip()) for _ in range(R)]
for i in range(R):
    if dfs(i, 0):
        answer += 1
print(answer)
