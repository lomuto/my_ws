# 베스트 앨범

[https://programmers.co.kr/learn/courses/30/lessons/42579#](https://programmers.co.kr/learn/courses/30/lessons/42579#)

---

<br/>   
   
자료구조의 중요성..
`key:value` 쌍을 이용해 풀어야하는 문제이다.   
  
데이터베이스 테이블 나누는 것 처럼 `장르, 재생수, 인덱스` 3가지 정보가 주어질 때 `장르, 재생수` 따로 `재생수, 인덱스` 따로 pair나 구조체를 두고 `장르,인덱스`를 `hash table`로 만들어 두개의 pair or 구조체를 정렬 후 `hash table`을 이용해 순서가 뒤바뀐 두 자료구조의 쌍을 찾아서 순서대로 출력하는 문제.   
   
hash table은 `map`을 이용하면 된다.   
   
**map 안에 원소 넣어줄때는 반드시 pair 형태로 넣어줄것**
   
```cpp
map<string,int> m;
...
m.insert(make_pair("Johnson",18));
```
