# 누울 자리를 찾아라 S5
# 구현, 문자열
n = int(input())
li = []
r, c = 0, 0
cnt = 0
for i in range(n):
    li.append(list(input()))
for i in range(n):
    cnt = 0
    for j in range(n):
        if li[i][j] == '.':
            cnt += 1
        else:
            cnt = 0
        if cnt == 2:
            r += 1
for i in range(n):
    cnt = 0
    for j in range(n):
        if li[j][i] == '.':
            cnt += 1
        else:
            cnt = 0
        if cnt == 2:
            c += 1
print(r, c)
