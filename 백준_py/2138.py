# 전구와 스위치 G5
# 그리디
n = input()
first = list(input())
target = list(input())


def change_zero_index(light):
    count = 1
    light[0] = str(1 - int(light[0]))
    light[1] = str(1 - int(light[1]))

    for i in range(1, len(light)):
        if target[i - 1] != light[i - 1]:
            count += 1
            light[i - 1] = str(1 - int(light[i - 1]))
            light[i] = str(1 - int(light[i]))
            if i != int(n) - 1:
                light[i + 1] = str(1 - int(light[i + 1]))

    if light == target:
        return count

    return 100001


def not_change_zero_index(light):
    count = 0

    for i in range(1, len(light)):
        if target[i - 1] != light[i - 1]:
            count += 1
            light[i - 1] = str(1 - int(light[i - 1]))
            light[i] = str(1 - int(light[i]))

            if i != int(n) - 1:
                light[i + 1] = str(1 - int(light[i + 1]))

    if light == target:
        return count

    return 100001


answer_first = change_zero_index(first[:])
answer_second = not_change_zero_index(first[:])
answer = min(answer_first, answer_second)

if answer == 100001:
    print(-1)
else:
    print(answer)
