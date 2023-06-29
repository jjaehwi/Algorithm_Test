# 인사성 밝은 곰곰이 S4
# 자료구조, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵
# 리스트로 구현시 시간초과
N = int(input())

dic = {}

cnt = 0

for _ in range(N):
    Input = input()

    if Input == "ENTER":
        for key, value in dic.items():
            if value == 1:
                cnt += 1
        dic = {}
    else:
        if Input not in dic:
            dic[Input] = 1

for key, value in dic.items():
    if value == 1:
        cnt += 1

print(cnt)
