# 숫자 카드 S5
# 자료 구조, 정렬, 이분 탐색, 해시를 사용한 집합과 맵
# dict 풀이
import sys

N = int(sys.stdin.readline())
cards = list(map(int, sys.stdin.readline().split()))
M = int(sys.stdin.readline())
checks = list(map(int, sys.stdin.readline().split()))

_dict = {}  # 속도는 dictionary!
for i in range(len(cards)):
    _dict[cards[i]] = 0  # 아무 숫자로 mapping

for j in range(M):
    if checks[j] not in _dict:
        print(0, end=" ")
    else:
        print(1, end=" ")

# 이진 탐색 풀이
# import sys

# N = int(sys.stdin.readline())
# cards = sorted(list(map(int, sys.stdin.readline().split())))
# M = int(sys.stdin.readline())
# checks = list(map(int, sys.stdin.readline().split()))

# for check in checks:
#     low, high = 0, N-1  # cards의 이진 탐색 index
#     exist = False
#     while low <= high:
#         mid = (low + high) // 2
#         if cards[mid] > check:  # 중간 값보다 작다면
#             high = mid - 1  # 중간보다 왼쪽 한 칸 옆까지 탐색
#         elif cards[mid] < check:  # 중간 값보다 크다면
#             low = mid + 1  # 중간보다 오른쪽 한 칸 옆부터 탐색
#         else:
#             exist = True
#             break
#     print(1 if exist else 0, end=' ')
