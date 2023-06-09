import sys

N = int(sys.stdin.readline())
table = [list(sys.stdin.readline().split()) for _ in range(N)]

table.sort(key=lambda x: (-int(x[1]), int(x[2]), -int(x[3]), x[0]))

for student in table:
    sys.stdout.write(str(student[0]) + "\n")

# 입력 요소가 리스트이며 정렬 기준을 key로 설정하기 위해서 lambda를 사용
# 이 lambda에 입력을 해줄때 리스트를 사용하면 원하는 순서대로 여러 개의 키를 동시에 적용
# 내림차순을 위해서는 -를 앞에 붙여줌으로써 해결
