# 삼각형 만들기 S3
# 그리디
import sys

n = int(sys.stdin.readline())
m = sorted([int(sys.stdin.readline()) for _ in range(n)], reverse=True)
answer = -1

# 그 어떤 삼각형도 어느 한 변의 길이가 나머지 두 변의 길이를 합한 것보다 길거나 같을 수 없다.
for i in range(n - 2):
    if m[i] < m[i + 1] + m[i + 2]:
        answer = m[i] + m[i + 1] + m[i + 2]
        break
print(answer)
