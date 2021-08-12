# 거짓말

[https://www.acmicpc.net/problem/1043](https://www.acmicpc.net/problem/1043)

1트: 해시셋.

입력으로 주어진 party에 참가하는 인원이 순서가 정해진게 아니라서

```cpp
// 4번이 진실을 암
3 1 2 3
2 3 4
```

이렇게 순차적으로 입력이 주어져도 후에 `3, 4` 가 나와도 `1, 2` 모두 진실을 알게됨.  
여기서 유니온파인드 떠올림.

<br/>   
   
2트: 유니온 파인트   
   
```cpp
pair<int,int> // 첫번째가 parent, second가 isLiar
```   
다음과 같은 원소의 set으로 해결.   
   
union 시    
   
```cpp
void unionSet(int a, int b) {
    int rootA = findSet(a);
    int rootB = findSet(b);

    if (rootA == rootB) {
        return;
    }

    peopleSet[rootB].first = rootA;
    peopleSet[rootA].second = peopleSet[a].second | peopleSet[b].second;

}

````
이와 같은 실수를 했는데, 이렇게 되면 입력 순서에 따라 진실을 아는 사람이 false로 덮어씌워진다.

``` cpp
peopleSet[rootB].first = rootA;
    peopleSet[rootA].second = peopleSet[rootA]].second | peopleSet[rootB].second;
````

이렇게 업데이트 해줄 root의 정보를 **root**의 논리합으로 수정해주면 된다.

### 유니온 파인드는 무조건 루트를 건드리자
