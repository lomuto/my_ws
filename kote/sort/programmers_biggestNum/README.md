# 가장 큰 수

[https://programmers.co.kr/learn/courses/30/lessons/42746](https://programmers.co.kr/learn/courses/30/lessons/42746)

[이 문제](./../bigNum_16469)랑 같은유형.

다른점이라면 `0 0 0 0`이 주어질 떄 문자열로 리턴하는거라 `"0000"` 이 리턴되면 틀리게됨.

전체가 0일때를 캐치해야하는데 나는 바보같이 전체 순회하면서 `flag` 세워서 0 개수를 세고 이 갯수가 입력값의 길이면 `"0"` 리턴하게 했음

```cpp
if(arr[0] == 0)
    return "0";
```

정렬이 잘 되어있으면 0이 아닌건 무조건 맨 앞`arr[0]` 에 오게 되어있음.  
`arr[0] == 0` 이면 전부 0이라는 뜻.

나같이 전체 다 돌면서 확인하는거보다 이게 더 clever 하다.
