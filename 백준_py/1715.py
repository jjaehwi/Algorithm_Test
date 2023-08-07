# 카드 정렬하기 G4
# 자료구조, 그리디, 우선순위 큐
import heapq
import sys

N = int(input())
card_deck = []
for _ in range(N):
    heapq.heappush(card_deck, int(sys.stdin.readline()))


if len(card_deck) == 1:  # 1개일 경우 비교하지 않아도 된다
    print(0)
else:
    answer = 0
    while len(card_deck) > 1:  # 1개일 경우 비교하지 않아도 된다
        temp_1 = heapq.heappop(card_deck)  # 제일 작은 덱
        temp_2 = heapq.heappop(card_deck)  # 두번째로 작은 덱
        answer += temp_1 + temp_2  # 현재 비교 횟수를 더해줌
        heapq.heappush(card_deck, temp_1 + temp_2)  # 더한 덱을 다시 넣어줌

    print(answer)
