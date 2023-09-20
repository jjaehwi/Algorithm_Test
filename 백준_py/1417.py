# 국회의원 선거 S5
# 그리디, 구현
n = int(input())  # 후보의 수
dasom = int(input())  # 기호 1번을 찍으려고 하는 사람의 수
vote = []  # 다른 후보를 찍으려고 하는 사람의 수
count = 0  # 매수해야하는 사람의 수
for _ in range(n - 1):
    vote.append(int(input()))
vote.sort(reverse=True)  # 내림차순 정렬
if n == 1:
    print(0)
else:
    # 표가 제일 많은 후보를 찍으려고 하는사람을 매수
    while vote[0] >= dasom:
        dasom += 1
        vote[0] -= 1
        count += 1
        vote.sort(reverse=True)
    print(count)
