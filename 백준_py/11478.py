# 서로 다른 부분 문자열의 개수 S3
# 자료구조, 문자열, 해시를 이용한 집합과 맵, 트리를 이용한 집합과 맵
s = input()
total = set()
for i in range(len(s)):
    for j in range(i, len(s)):
        total.add(s[i : j + 1])  # i번째 문자부터 부분문자열 구하기

print(len(total))
