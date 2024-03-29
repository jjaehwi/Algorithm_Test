# 그리디 알고리즘 (탐욕법)

- 그리디 알고리즘 (탐욕법)은 현재 상황에서 `지금 당장 좋은 것만 고르는 방법`을 의미한다.

- 단순히 가장 좋아보이는 것을 반복적으로 선택해도 최적의 해를 얻을 수 있는지 검토한다.

- 코딩 테스트 에서는 일반적으로 어떠한 입력이 주어졌을 때 어떠한 출력 값이 나와야 하는 것을 미리 출제자가 정해놓고 문제를 만드는 경우가 많기 때문에, 만약 그리디 문제가 출제된다면 `탐욕법으로 얻은 해가 최적의 해가 되는 상황에서, 단순히 그리디 알고리즘을 이용해도 최적의 해를 얻을 수 있다는 것을 추론`할 수 있어야 문제가 풀리도록 출제하는 경우가 많다.

- 즉, 흔히 코딩테스트 문제 중에서 그리디 알고리즘 (탐욕법) 으로 분류가 되는 문제들은 탐욕법으로 얻은 해가 최적의 해가 되는 경우에 한해서 문제를 출제하는 경우가 많다.

## 그리디와 DP의 차이

- 그리디는 현재 상황에서만 대해 계산을 하면되고, dp는 부분문제의 결과값을 이용한다.

- 현 상황에 대해 최적만 골랐을 때 해가 최적이고 반례가 없으면 그리디를 써도 되고 반례가 있다면 dp를 써야한다. 크루스칼 알고리즘은 그리디이다.

- [참고링크](https://www.acmicpc.net/board/view/46178)
