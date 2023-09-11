# 팔 S1
# 그리디
A, B = map(str, input().split(" "))

ret = 0

if len(A) != len(B):
    print(0)

else:
    for i in range(len(A)):
        if A[i] == B[i]:
            if A[i] == "8":
                ret += 1
        else:
            break
    print(ret)
