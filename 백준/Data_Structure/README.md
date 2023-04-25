# 자료 구조

- 우선 순위 큐 참고 https://travelbeeee.tistory.com/126

- 이분 탐색 (binary_search) (참고 : BarkingDog 블로그)

  - `binary_search` 를 통해 target 이 주어진 범위 내에 있는지 true, false 를 알 수 있다. (백준 1920번)

  - `upper_bound` 를 통해 target 이 들어갈 수 있는 가장 오른쪽 위치를 반환 (백준 10816번)

  - `lower_bound` 를 통해 target 이 들어갈 수 있는 가장 왼쪽 위치를 반환

  - `erase` 와 `unique` 를 통해 `배열에서 중복되는 값을 제거`할 수 있다. (백준 18870번)

  - **추가적으로 뭔가 2 개의 값을 묶은 후 어느 한쪽의 값을 이분 탐색으로 찾아서 시간복잡도를 낮추는 아이디어는 이분탐색 관련 응용문제에서 핵심적으로 많이 나온다.** (백준 2295번)

  - `parametric search (매개 변수 탐색)` 문제는 조건을 만족하는 최소/최댓값을 구하는 문제, 즉 **`최적화 문제를 결정 문제로 변환`해 이분탐색을 수행하는 방법**이다. (백준 1654번)

    - 문제에서 최소 혹은 최대 얘기가 있고 범위가 무지막지하게 크거나, 뭔가 시간복잡도에서 값 하나를 로그로 어떻게 잘 떨구면 될 것 같을 때 parametric search 풀이가 가능하지는 않을까 고민을 해볼 필요가 있다.

```
// 백준 1920번
binary_search(arr, arr + n, target)
```

```
// 백준 10816번
upper_bound(arr, arr + n, target) - lower_bound(arr, arr + n, target)
```

```
// unique 가 끝나면 반환되는 값은 vector 의 쓰레기값 첫번째 위치
uni.erase(unique(uni.begin(), uni.end()), uni.end());
```

- 세그먼트 트리
