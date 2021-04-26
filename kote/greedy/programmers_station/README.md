# 기지국 설치

[https://programmers.co.kr/learn/courses/30/lessons/12979](https://programmers.co.kr/learn/courses/30/lessons/12979)

칸이 최대 2억이라 하나하나 다 보면 시간초과가 뜨는 문제.

기지국 하나의 커버리지가 정해져 있으므로,  
칸의 첫부터 시작해 기지국이 커버 가능한 범위를 `pair`로 vector에 저장해 `if( i > isp[s].first )` 인 경우 `cnt` 1만 증가시키고 i는 pair의 `second`로 넘겨주면 그만큼 생략이 가능.

vector를 다 돌았는데도 커버되지 않은 칸이 남아있다면 cnt에 `남은범위 / 기지국 하나의 커버리지` 를 더해주는데 나머지가 있다면 하나를 더 더해줌.

---

<br/>   
   
### 배열이 0부터 시작하는거 때문에 인덱스 처리에서 쓸데없이 시간을 보낸 문제.... 안헷갈리게 할꺼면 0번 index 버리고 배열크기 1 더해주던가 하자
