# 커트라인 B2
# 구현, 정렬
n, k = map(int, input().split())
scores = list(map(int, input().split()))
scores.sort(reverse=True)
print(scores[k - 1])
