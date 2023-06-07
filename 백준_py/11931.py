# 수 정렬하기 4 S5
# 정렬
import sys
input = sys.stdin.readline

n = int(input())
nums = [int(input()) for _ in range(n)]
nums.sort(reverse=True)
for num in nums:
    print(num)
