# 대표값2 B2
# 수학, 구현, 사칙연산
x = []
for i in range(5):
    x.append(int(input()))
x.sort()
print(int(sum(x) / 5))
print(x[2])
