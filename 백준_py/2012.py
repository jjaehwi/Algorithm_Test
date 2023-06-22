# 등수 매기기 S3
# 그리디
import sys
n = int(sys.stdin.readline())
vals = []
for _ in range(n):
    vals.append(int(sys.stdin.readline()))

vals.sort()

diff = 0
for i in range(1, n+1):
    diff += abs(i - vals[i-1])

print(diff)
