# 골드바흐 파티션 S2
# 수학, 정수론, 소수 판정, 에라토스테네스의 체
import sys

prime = []
check = [0] * 1000001
check[0] = 1
check[1] = 1

for i in range(2, 1000001):
    if check[i] == 0:
        prime.append(i)
        for j in range(2 * i, 1000001, i):
            check[j] = 1

T = int(sys.stdin.readline())

for _ in range(T):
    count = 0
    N = int(sys.stdin.readline())
    for i in prime:
        if i >= N:
            break
        if not check[N - i] and i <= N - i:  # 순서만 다른거 counting 하지 않기 위해
            count += 1
    print(count)
