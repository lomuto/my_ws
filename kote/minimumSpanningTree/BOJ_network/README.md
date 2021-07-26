# 네트워크

이전에 OOP 적으로 구현했던 mst 를 ps 스럽게 도전해봤다.  
node의 인덱스를 key로 가지고 Node 개체를 value로 가지는 HashMap 대신에 배열을 만들어서, 배열의 `i`번 인덱스 안의 원소는 `i`노드의 부모가 되게끔 구현.

이렇게 했을 때 문제가...

```cpp
void unionSet(int vertex0, int vertex1) {
    if (findSet(vertex0) == findSet(vertex1)) {
        return;
    }

    verticies[vertex1] = findSet(vertex0);
}
```

union 부분만 따온건데 이 코드는 틀리다.  
현재 vertex0,1을 원소로 하는 트리(set)이 동일하지 않을 때

```cpp
verticies[vertex1] = findSet(vertex0);
```

이 부분에서 verticies를 업데이트 해주어야 하는데 위에도 언급했다싶이 vertex을 **원소**로 가지는 set이 같냐 다르냐를 따지므로 위의 코드는 **vertex1 을 포함하는 set과 vertex0을 포함하는 set끼리의 union이 아닌 vertex1만 vertex0의 set에 포함시키는 코드이다**

</br>

코드를 옳게 고치면

```cpp
 verticies[findSet(vertex1)] = findSet(vertex0);
```

와 같이 vertex1의 루트를 합쳐주어야 한다...
