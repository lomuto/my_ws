# 구명보트

[https://programmers.co.kr/learn/courses/30/lessons/42885](https://programmers.co.kr/learn/courses/30/lessons/42885)

```
보트 하나당 limit 만큼의 무게를 태울 수 있다.
각 사람의 몸무게가 주어질 때
사람 모두를 태워 보낼 수 있는 배의 최소갯수를 구하라
```

1. 일단 정렬  
   오름차순으로 정렬한다.  


<br/>   
   
정렬 이후에 몸무게 낮은사람순으로 묶어서 둘씩 보내면 되지 않을까 싶었는데   
```cpp
// limit 이 100일 때
30,40,60,70
```   
같은 경우는 `[30,40],[60],[70]` 일텐데 이는 `[30,70],[40,60]` 보다 배를 하나 더 보내는거임.   
   
**정렬된 배열에서 시작과 끝에 pivot을 하나씩 둬서 `people[st] + people[end] <= limit` 일 때 두명이 보트 하나 타고 가는경우로 숫자를 세면 된다.**   
```cpp
for (int st = 0, end = SIZE - 1; st < end; end--) {
        if (people[st] + people[end] <= limit) {
            cnt -= 1;
            st++;
        }
    }
```
종료조건은 `st<end` 일때이다.   
**정렬된 배열 이라는 전제조건 하에, `end` pivot의 경우는 `people[st] + people[end] <= limit` 인 지점을 찾았을 때 이전의 `end`보다 작은 값이므로 `st<end` 를 만족할때까지 계속 `end--` 해도 된다.**
