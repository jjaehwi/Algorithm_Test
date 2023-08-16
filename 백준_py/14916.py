# 거스름돈 S5
# 수학, 그리디, dp
n = int(input())

cnt = 0
i = 0
while True:
    if n % 5 == 0:  # 5의배수이면 or 2로만 거슬러주고 n이 0이된경우
        cnt += n // 5  # 5로나눈 몫이 정답
        break
    else:
        n -= 2  # 5의배수가 아니면 2백원씩 뺴면서 5로 나누어떨어지는것이 나오도록
        cnt += 1

    if n < 0:  # 2백원씩 뺏더니 음수가 되버린경우 --> 거슬러줄수 없을을 의미함
        break
if n < 0:  # 음수면 거슬러줄수없
    print(-1)
else:
    print(cnt)
