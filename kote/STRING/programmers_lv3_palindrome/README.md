# 가장 긴 펠린드롬

[https://programmers.co.kr/learn/courses/30/lessons/12904](https://programmers.co.kr/learn/courses/30/lessons/12904)

---

<br/>
   
## 2021.4.27 문제 다시 풀어봤음   
   
```
1트: pivot st,end 두고 st는 0부터 end 까지 커지면서 각 구간의 팰린드롬 검사. 문자열의 길이가 들쭉날쭉 하므로 최대값 보장x
2트: 최대값을 찾기 위해 변수 MAX 둬서 MAX = max(MAX,end-st+1). 시간복잡도 n^2 지수시간.   
3트: 아래 적힌 풀이처럼 풀었음. 부분문자열의 길이를 줄여나가는 반복문 안에서 부분문자열이 문자열 내에서 왔다갔다 하면서 팰린드롬 검사
4트: 반복문이 그냥 종료 == 팰린드롬 없음 == 최대 팰린드롬의 길이는 1. 반복문 그냥 종료시 return 1 추가. tc 17,18이 그래서 실패했었음 
```

---

<br/>

펠린드롬같은 경우 `left`,`right` pivot두개둬서 문자열 양 끝에서 `left<right` 일때까지 문자 같은지 쪼여오는게 정석이라 접근은 어렵지 않았다.

종료조건이 **`left<=right`** 인지 조금 헷갈렸는데, **문자열의 길이가 짝수던 홀수던 `left==right` 인 순간은 짝수에서는 없고 홀수에서는 무조건 통과이므로** 조건을 **`left<right`** 으로 놓아야 한다.

---

<br/>   
   
최대 길이의 펠린드롬을 찾아야 하므로 가장 큰 타일을 찾는 문제처럼 비교할 문자열의 길이를 최대부터 줄여가면서 문자열 시작부터 끝가지 대보아야 하는 `지수시간`의 2중 for문을 써야한다.   
   
비교할 문자열의 처음과 끝을 `pair<int,int> p` 로 관리해   
1씩 증가하는 `i` 의 바깥 for문에서 `p.second = init_p_second-i` 로 비교 할 문자열의 길이를 하나씩 줄여나간다.   
`init_p_second` 는 시작시기의 문자열의 끝, 즉 문자열의 마지막 문자의 index가 되는데 **p.second = p.second-i** 와 같이 내가 처음 한 실수를 하면 길이가 7인 문자열에 대해 **`7->6->4->1`** 처럼 `7 6 5 4..` 같이 문자열의 길이가 1씩 줄어들지 않게 된다. 실수하지 말자.

<br/>

안쪽 for문에서는 `pair`에 따라

```cpp
for(int j=0; p.second+j < SIZE; i++){
    int left = p.first+j;
    int right = p.second+j;
    while(left < right){
        if(s[left] == s[right]){
            left++;
            right--;
        }
        else
            break;
    }
    if(left > right)
        return p.first - p.second + 1;
}
```

고정된 `pair` 에 따라 `pair의 끝 + iterator[j]` 가 문자열의 끝일때까지 펠린드롬을 검사한다.  
while문 종료 시 `s[left] == s[right]`임을 검사하고 `left`와 `right`을 1씩 늘리고 줄였으므로 `left > right` 이어야지 펠린드롬이다.
