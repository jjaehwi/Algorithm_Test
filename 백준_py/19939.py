# 박 터뜨리기 S4
# 그리디
import sys

read = sys.stdin.readline

N, K = map(int, read().rstrip().split())

minimum = K * (K + 1) // 2

if minimum > N:
    print(-1)
elif (N - minimum) % K == 0:
    print(K - 1)
else:
    print(K)
