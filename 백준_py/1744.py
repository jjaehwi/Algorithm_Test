# 수 묶기 G4
# 그리디, 정렬
N = int(input())
positive = []  # 양수를 저장할 리스트
negative = []  # 음수를 저장할 리스트
max_sum = 0

for _ in range(N):
    n = int(input())

    if n > 1:
        positive.append(n)
    elif n == 1:
        max_sum += 1  # 1, 양수의 규칙에 의해 1을 더한다.
    else:
        negative.append(n)

positive.sort(reverse=True)  # 양수의 큰 수부터 정렬한다.
negative.sort()  # 음수의 작은 수부터 정렬한다.

# 양수 리스트 더해주기
if len(positive) % 2 == 0:  # 양수가 짝수개 일경우 두개씩 곱해준다.
    for i in range(0, len(positive), 2):
        max_sum += positive[i] * positive[i + 1]
else:
    for i in range(0, len(positive) - 1, 2):
        max_sum += positive[i] * positive[i + 1]
    max_sum += positive[len(positive) - 1]  # 마지막 수는 더해준다.

# 음수 더해주기
if len(negative) % 2 == 0:  # 음수가 짝수개 일경우 두개씩 곱해준다.
    for i in range(0, len(negative), 2):
        max_sum += negative[i] * negative[i + 1]
else:
    for i in range(0, len(negative) - 1, 2):
        max_sum += negative[i] * negative[i + 1]
    max_sum += negative[len(negative) - 1]  # 마지막 수는 더해준다.

print(max_sum)
