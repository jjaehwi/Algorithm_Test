# 피보나치 수의 확장 S3
# 수학, dp
n = int(input())
s = [0, 1]
for i in range(2, abs(n) + 1):
    s.append((s[i - 1] + s[i - 2]) % 1000000000)
if n % 2 == 0 and n < 0:
    print(-1)
elif n == 0:
    print(0)
else:
    print(1)
print(s[abs(n)])
