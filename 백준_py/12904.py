# A와 B G5
# 구현, 그리디
S = list(map(str, input()))
T = list(map(str, input()))

while len(S) != len(T):
    if T[-1] == "A":
        T.pop()
    elif T[-1] == "B":
        T.pop()
        T = T[::-1]

if S == T:
    print(1)
else:
    print(0)
