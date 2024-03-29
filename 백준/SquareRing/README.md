# 거의 제곱 고리

## 문제

1부터 N까지의 자연수를 원 모양으로 배열했을 때 연속된 두 수의 합이 항상 어떤 정수의 제곱이 되면 이 배열을 완전 제곱 고리(perfect square circle)라 부른다.
아래 <그림 1>은 N=32인 완전 제곱 고리의 한 예시이다.
그리고 놀랍게도 어떤 프로그래머가 N이 25 이상 1,048,576 이하일 때 완전 제곱 고리가 존재함을 보였다.

![그림1](https://user-images.githubusercontent.com/87372606/208299194-230caaee-4657-45ad-a61a-c2be21a6186c.png)
<그림 1>

사실, 1부터 N까지 배열하는 모든 수의 경우의 수를 고려하여 완전 제곱 고리를 찾는 것은 매우 힘든 일이다. 고작 N이 13만 돼도 고려해야 하는 연산의 횟수가 60억이 넘는다.
그런데 완전 제곱 고리를 본 헤인즈는 서로 다른 N개의 자연수를 원 모양으로 배열했을 때 연속된 두 수의 합 중 제곱수가 가장 많이 나오는 경우를 알고 싶어졌다.
그리고 헤인즈는 이 경우를 거의 제곱 고리라고 부르기로 했다.
<그림 2>는 1, 3, 6, 8이 주어졌을 때 원 모양으로 배열하는 모든 경우의 수이다.
거의 제곱 고리는 2 종류가 있으며 이 때 연속된 두 수의 합이 제곱이 되는 경우는 최대 3번이며, 빨간색 박스에 들어 있는 경우가 거의 제곱 고리이다.

![2](https://user-images.githubusercontent.com/87372606/208299048-b08cc769-4c8d-4a4b-8c64-56b5a7a5c02c.png)
<그림 2>

`서로 다른 N개의 자연수가 주어졌을 때 거의 제곱 고리에 존재하는 연속된 두 수의 합이 제곱수가 되는 개수를 구하여라.`

### 제한 사항

    1. 서로 다른 숫자의 개수 N 은 4 이상 10 이하이다.
    2. 주어지는 서로 다른 숫자는 1000 이하이다.

### 입력

    맨 처음 테스트 케이스의 개수 T가 주어지며 그 다음 T개의 테스트 케이스가 주어진다.
    각 테스트 케이스는 두 줄로 이루어져있다.
    첫 번째 줄에는 서로 다른 숫자의 개수 N이 주어진다.
    두 번째 줄에는 서로 다른 자연수 N개가 공백으로 구분되어 주어진다.

### 출력

    테스트 케이스 하나 당 한 줄씩 출력한다.
    맨 처음 #x (x 는 테스트케이스 번호, 1부터 시작)을 출력하고 공백을 하나 둔 후,
    거의 제곱 고리에 존재하는 연속된 두 수의 합이 제곱수가 되는 횟수를 출력한다.

### 예시

    입출력 예
    (입력)
    1
    4
    1 3 6 8

    (출력)
    #1 3

### sample_input.txt에 대한 출력

#1 2

#2 1

#3 4

#4 0

#5 5

#6 4

#7 1

#8 4

#9 6

#10 0

#11 5

#12 7

#13 0

#14 6

#15 7

#16 8

#17 7

#18 9

#19 10

#20 8
