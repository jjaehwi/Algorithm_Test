# 행렬 곱셈 S5
# 수학, 구현, 선형대수학
# 파이썬 행렬 곱셈은 N*M 행렬과 M*K 행렬이 만나 N*K행렬을 만든 다는 것만 기억하면 된다.
N, M = map(int, input().split())
A = []
for _ in range(N):
    A.append(list(map(int, input().split())))

M, K = map(int, input().split())
B = []
for _ in range(M):
    B.append(list(map(int, input().split())))


# 행렬 곱셈
C = [[0 for _ in range(K)] for _ in range(N)]

for n in range(N):
    for k in range(K):
        for m in range(M):
            C[n][k] += A[n][m] * B[m][k]

# 출력문
for i in C:
    for j in i:
        print(j, end=" ")
    print()
