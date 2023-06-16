# 가로세로퍼즐 S2
# 브루트포스, 구현
arr = [input() for _ in range(6)]
arr.sort()
ans_list = []
for i in range(6):
    for j in range(6):
        for k in range(6):
            if i == j or i == k or j == k:
                continue
            temp = [arr[i], arr[j], arr[k]]
            temp2 = temp.copy()
            for h in range(3):
                temp2.append(temp[0][h] + temp[1][h] + temp[2][h])
            temp2.sort()
            if arr == temp2:
                ans_list.append(temp[0] + temp[1] + temp[2])
ans_list.sort()
if len(ans_list):
    for i in range(0, 10, 3):
        print(ans_list[0][i:i + 3])
else:
    print(0)
