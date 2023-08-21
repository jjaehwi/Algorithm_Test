# 라면 사기 (Small) D5
# 그리디
# 3개 -> 2개 -> 1개 각 지점마다 살수있는 만큼 사주면 된다.
# 주의할 점은 두번째 지점의 갯수가 세번째보다 큰경우. 이경우는 2개씩 사는 과정을 먼저 해주어야한다.
import sys

input = sys.stdin.readline


def buy_triple(idx):
    global cost
    k = min(arr[idx : idx + 3])
    arr[idx] -= k
    arr[idx + 1] -= k
    arr[idx + 2] -= k
    cost += 7 * k


def buy_double(idx):
    global cost
    k = min(arr[idx : idx + 2])
    arr[idx] -= k
    arr[idx + 1] -= k
    cost += 5 * k


def buy_each(idx):
    global cost
    cost += 3 * arr[idx]


N = int(input())
arr = list(map(int, input().split())) + [0, 0]
cost = 0
for i in range(N):
    if arr[i + 1] > arr[i + 2]:
        k = min(arr[i], arr[i + 1] - arr[i + 2])
        arr[i] -= k
        arr[i + 1] -= k
        cost += 5 * k

        buy_triple(i)
    else:
        buy_triple(i)
        buy_double(i)
    buy_each(i)
print(cost)
