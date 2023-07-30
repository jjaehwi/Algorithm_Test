# 행렬 S1
# 그리디
n, m = map(int, input().split())
listA = []
for _ in range(n):  # 리스트A 선언
    listA.append(list(map(int, list(input()))))
listB = []
for _ in range(n):  # 리스트B 선언
    listB.append(list(map(int, list(input()))))


def check(i, j):  # 뒤집기 함수
    for x in range(i, i + 3):
        for y in range(j, j + 3):
            if listA[x][y] == 0:
                listA[x][y] = 1
            else:
                listA[x][y] = 0


cnt = 0  # 카운트
if (n < 3 or m < 3) and listA != listB:
    # 예외 1, 리스트가 작을 때
    cnt = -1
else:
    for r in range(n - 2):
        for c in range(m - 2):
            if listA[r][c] != listB[r][c]:
                cnt += 1
                check(r, c)

if cnt != -1:
    if listA != listB:  # A와 B가 같은지 확인
        cnt = -1
print(cnt)
