# 요세푸스 문제 0 S5
# 구현, 자료구조, 큐
import sys

# 입력 받기
n, k = map(int, sys.stdin.readline().split())

# 요세푸스 순열 생성
idx = 0
queue = [i for i in range(1, n + 1)]
res = []
while queue:
    idx += k - 1  # k-1번째 인덱스까지 건너뛰기
    if idx >= len(queue):  # 인덱스가 범위를 넘어갈 경우
        idx %= len(queue)  # 나머지 연산을 통해 인덱스 계산
    res.append(str(queue.pop(idx)))  # k번째 수 제거 후 결과 배열에 추가

# 결과 출력
print("<", ", ".join(res), ">", sep="")
