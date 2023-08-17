# 안테나 S3
# 수학, 그리디, 정렬
n = int(input())
house_li = []
house_li = list(map(int, input().rstrip().split()))
house_li.sort()
print(house_li[(n - 1) // 2])
