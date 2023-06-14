# 팩토리얼 0 의 개수 S5
# 수학
# math.factorial을 통해 n 팩토리얼을 계산한 뒤, str로 바꿔주고 뒤집기
# 이후 0 이 끝날 때까지 개수를 세주고, 끝나면 break.
from math import factorial
n = int(input())
cnt = 0
for x in str(factorial(n))[::-1]:
    if x != '0':
        break
    cnt += 1
print(cnt)
