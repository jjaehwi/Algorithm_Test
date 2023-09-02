# 별 찍기 18 G4
# 구현, 재귀
n = int(input())
row = 2**n - 1
col = 2 * row - 1
canvas = [[" "] * col for i in range(row)]


# 기준은 맨 왼쪽 위를 0,0 으로 잡고 호출
def draw(x, y, n):
    row = 2**n - 1  # 현재 그릴 삼각형의 행 갯수
    col = 2 * row - 1  # 현재 그릴 삼각형의 열 갯수

    if n == 1:
        canvas[x][y] = "*"
        return

    if n % 2:  # 홀수일 경우
        # 이번 삼각형 그리기
        # 각 줄마다 양 끝점 두개 채우기
        for i in range(row - 1, -1, -1):
            canvas[x + row - i - 1][y + i] = "*"
            canvas[x + row - i - 1][y + col - 1 - i] = "*"
            # 맨 아랫줄 채우기
            if i == 0:
                for j in range(1, col - 1):
                    canvas[x + row - 1][y + j] = "*"
        # 다음 삼각형 호출
        draw(x + 2 ** (n - 1) - 1, y + 2 ** (n - 1), n - 1)

    else:  # 짝수일 경우 (역삼각형)
        # 이번 삼각형 그리기
        # 양 끝점들 채우기
        for i in range(row):
            canvas[x + i][y + i] = "*"
            canvas[x + i][y + col - 1 - i] = "*"
            # 맨 윗줄 채우기
            if i == 0:
                for j in range(1, col - 1):
                    canvas[x][y + j] = "*"
        # 다음 그릴 삼각형 호출
        draw(x + 1, y + 2 ** (n - 1), n - 1)


draw(0, 0, n)
for line in canvas:
    print("".join(line).rstrip())
