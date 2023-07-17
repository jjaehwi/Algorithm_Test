# 나이순 정렬 S5
# 정렬
n = int(input())
member_lst = []

for i in range(n):
    age, name = map(str, input().split())
    age = int(age)
    member_lst.append((age, name))

member_lst.sort(key=lambda x: x[0])  ## (age, name)에서 age만 비교

for i in member_lst:
    print(i[0], i[1])
