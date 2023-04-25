# 자료 구조

- 우선 순위 큐 참고 https://travelbeeee.tistory.com/126

- 이분 탐색 (binary_search)

  - `binary_search` 를 통해 target 이 주어진 범위 내에 있는지 true, false 를 알 수 있다. (백준 1920번)

  - `upper_bound` 를 통해 target 이 들어갈 수 있는 가장 오른쪽 위치를 반환 (백준 10816번)

  - `lower_bound` 를 통해 target 이 들어갈 수 있는 가장 왼쪽 위치를 반환

  - `erase` 와 `unique` 를 통해 `배열에서 중복되는 값을 제거`할 수 있다. (백준 18870번)

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
