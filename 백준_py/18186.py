# 라면 사기 (Large) D4
# 그리디
import sys

input = sys.stdin.readline


def buy_triple(idx):
    global cost
    k = min(arr[idx : idx + 3])
    arr[idx] -= k
    arr[idx + 1] -= k
    arr[idx + 2] -= k
    cost += (B + 2 * C) * k


def buy_double(idx):
    global cost
    k = min(arr[idx : idx + 2])
    arr[idx] -= k
    arr[idx + 1] -= k
    cost += (B + C) * k


def buy_each(idx):
    global cost
    cost += B * arr[idx]


N, B, C = map(int, input().split())
if B < C:
    C = B
arr = list(map(int, input().split())) + [0, 0]
cost = 0
for i in range(N):
    if arr[i + 1] > arr[i + 2]:
        k = min(arr[i], arr[i + 1] - arr[i + 2])
        arr[i] -= k
        arr[i + 1] -= k
        cost += (B + C) * k

        buy_triple(i)
    else:
        buy_triple(i)
        buy_double(i)
    buy_each(i)
print(cost)
