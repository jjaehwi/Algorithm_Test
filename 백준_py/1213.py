# 팰린드롬 만들기 S3
# 그리디
import sys
from collections import Counter

word = list(map(str, sys.stdin.readline().strip()))
word.sort()  # 사전순으로 정렬하기 위해 오름차순 정렬
check = Counter(word)  # 홀수의 개수를 확인하기 위해 Counter 함수 사용

cnt = 0  # 홀수의 개수
center = ""  # 홀수의 문자

# 반복문을 통해 각 문자의 개수를 확인
for i in check:
    # 문자의 개수가 홀수일 경우
    # 홀수의 개수를 카운트하고 홀수의 문자를 더해준다.
    if check[i] % 2 != 0:
        cnt += 1
        center += i
        word.remove(i)  # 홀수의 문자 하나를 문자열에서 제거

    # 홀수의 개수가 1보다 클 경우 팰린드롬으로 바꾸지 못한다.
    if cnt > 1:
        break

# 홀수의 개수가 1보다 클 경우 팰린드롬으로 바꾸지 못한다.
if cnt > 1:
    print("I'm Sorry Hansoo")

# 홀수의 개수가 1 이하일 경우에는 팰린드롬으로 바꿀 수 있다.
else:
    res = ""
    # 반복문을 통해 팰린드롬을 반을 나누었을 때 왼쪽 부분을 더해준다.
    for i in range(0, len(word), 2):
        res += word[i]

    # 왼쪽 + 가운데(홀수) + 오른쪽
    print(res + center + res[::-1])
