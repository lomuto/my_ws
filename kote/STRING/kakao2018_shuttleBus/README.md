# 셔틀버스

[https://programmers.co.kr/learn/courses/30/lessons/17678](https://programmers.co.kr/learn/courses/30/lessons/17678)

---

<br/>

2021.4.25 통과실패

주어지는 시간을 처음에는 `시간:분` 을 통째로 받았다

```cpp
for(int i=0; i<time.size(); i++){
    string buf = time[i];
    string arrivingTime = "";
    arrivingTime += time[0];
    arrivingTime += time[1];
    arrivingTime += time[3];
    arrivingTime += time[4];
}
```

`09:12` 처럼 문자열이 주어지므로 `arrivingTime` 에는 `912` 가 저장.  
시간과 분이 구분이 안되므로 코드를 자료구조를 `pair` 로 갈아엎었다.

```cpp
vector<pair<int,int>> arrivingTime;

for(int i=0; i<time.size(); i++){
    string buf = time[i];
    string hour = "";
    string min = "";
    hour += time[0];
    hour += time[1];
    min += time[3];
    min += time[4];
    arrivingTime[i].first = atoi(hour.c_str());
    arrivingTime[i].second = atoi(min.c_str());
}
```

이렇게하니까 분이 60을 넘어갈때를 고려해줘야 해서 나중에 반복문이 너무 더럽게 나왔다.

**앞으로 시간:분 같은 시간이 문자열로 주어지면 무조건 최소단위로 변환해서 대소 비교하기**

```cpp
vector<int> arrivingTime;

for(int i=0; i<time.size(); i++){
    string buf = time[i];
    string hour = "";
    string min = "";
    hour += time[0];
    hour += time[1];
    min += time[3];
    min += time[4];
    arrivingTime[i] = atoi(hour.c_str())*60;
    arrivingTime[i] += atoi(min.c_str());
}
```

이렇게하면 배열 `arrivingTime` 에는 최소단위인 분단위로 시간이 저장돼 대소비교하기 훨씬 편하다.
