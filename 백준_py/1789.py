# 수들의 합 S5
# 수학, 그리디
s = int(input())
total = 0
count = 0

while True:
    count += 1
    total += count
    if total > s:
        break

print(count - 1)
