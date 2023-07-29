# 신입 사원 S1
# 그리디
import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    rank = [list(map(int, input().split())) for _ in range(N)]
    rank_asc = sorted(rank)
    top = 0
    result = 1

    for i in range(1, len(rank_asc)):
        if rank_asc[i][1] < rank_asc[top][1]:
            top = i
            result += 1

    print(result)
