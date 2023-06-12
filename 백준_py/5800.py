# 성적 통계 S5
# 구현, 정렬
x = int(input())

for i in range(x):

    a = list(map(int, input().split()))
    del a[0]
    a.sort()
    diff = []
    print('Class', i+1)
    for i in range(len(a)-1):
        diff.append(a[i+1] - a[i])

    print('Max', str(max(a))+',', 'Min',
          str(min(a))+',', 'Largest gap', max(diff))
