# 1로 만들기

[https://www.acmicpc.net/problem/1463](https://www.acmicpc.net/problem/1463)

<br/>

간과했던 점.  
Test case 10의 경우 `10 -> 9 -> 3 -> 1` 이 최적  
조건문을

```cpp
if(!(i%3))
    ...
else if(!(i%2))
    ...
else    // i-1
    ...
```

이렇게 짜느라 `10 -> 9` 가 되지 못하고 `10 -> 5` 로 가버림.

```cpp
if(!(i%6))
    min(i-1, min(i/3,i/2));
else if(!(i%3))
    ...
else if(!(i%2))
    ...
else    // i-1
    ...
```

i가 2와3의 공약수일때를 고려한 조건문 추가.

**그리고 `!i%3` 은 연산자 우선순위때문에 `0%3`이 된다.**  
**꼭 `!(i%3)` 신경써주기**
