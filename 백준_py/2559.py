# 수열 S3
# 누적 합, 두 포인터, 슬라이딩 윈도우
import sys
input = sys.stdin.readline

n, k = map(int, input().split())
a = list(map(int, input().split()))

result = []
result.append(sum(a[:k]))

for i in range(n - k):
    result.append(result[i] - a[i] + a[k+i])

print(max(result))
