# DNA S4
# 구현, 문자열, 그리디
n, m = map(int, input().split())

arr = []

# 문자열을 list형식으로 담아준다
for i in range(n):
    arr.append(list(map(str, input())))

cnt, hap = 0, 0
result = ""
for i in range(m):
    a, c, g, t = 0, 0, 0, 0
    for j in range(n):
        if arr[j][i] == "T":
            t += 1
        elif arr[j][i] == "A":
            a += 1
        elif arr[j][i] == "G":
            g += 1
        elif arr[j][i] == "C":
            c += 1
    if max(a, c, g, t) == a:
        result += "A"
        hap += c + g + t
    elif max(a, c, g, t) == c:
        result += "C"
        hap += a + g + t
    elif max(a, c, g, t) == g:
        result += "G"
        hap += a + c + t
    elif max(a, c, g, t) == t:
        result += "T"
        hap += c + g + a

print(result)
print(hap)
