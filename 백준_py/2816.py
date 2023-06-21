# 디지털 티비 B1
# 구현
def cursorDown(cursor):
    cursor += 1
    print(1, end='')
    return cursor


def channelUp(cursor):
    if cursor > 0:
        cList[cursor], cList[cursor-1] = cList[cursor-1], cList[cursor]
        cursor -= 1
        print(4, end='')
    return cursor


cList = []

for _ in range(int(input())):
    cList.append(input())

cursor = 0
while True:
    if cList[cursor] != 'KBS1':
        cursor = cursorDown(cursor)
    else:
        cursor = channelUp(cursor)
    if cList[0] == 'KBS1':
        break

while True:
    if cList[cursor] != 'KBS2':
        cursor = cursorDown(cursor)
    else:
        cursor = channelUp(cursor)
    if cList[1] == 'KBS2':
        break
