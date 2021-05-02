# 홀짝 칵테일

[https://www.acmicpc.net/problem/21312](https://www.acmicpc.net/problem/21312)

---

<br/>   
   
문제 난이도가 높은건 아닌데 정렬하는데서 시간을 많이 까먹었음.   
  
`sort` 함수의 세번째 인자로 함수 포인터를 넘겨줘서 특정 조건에 맞는 정렬을 할 수 있다.   
이 때   
   
1. 홀수가 짝수보다 앞에 오면서
2. 같은 홀수거나 짝수면 큰수가 앞에오게
이와같은 정렬을 수행하는 함수 `cmp` 를 만들어보자,   
   
```cpp
bool cmp(int a, int b){
    if(a&1 && b&1)
        return a>b;
    else if(a&1)
        return true;
    else if(b&1)
        return false;
    else
        return a>b;
}
```   
   
a와b 모두 홀수이면 내림차순.   
   
중요한건 여기서부터인데,   
**기존의 배열에서 앞에있는게 a, 뒤에 있는게 b 이므로** a가 홀수라면 앞에 있는게 맞으므로 **ture를 리턴한다**   
반대로 b가 홀수라면 b가 a보다 앞에 있어야 하므로 false를 리턴.   
   
둘다 짝수라면 `return a>b` 를 해줌으로써 더 큰걸 return 한다.   
   
---   
   
<br/>   
   
cmp 함수에서 단순 대소비교가 아니라 조건부로 비교하는 경우 특정 조건일 경우 true 또는 false 를 반환하는 테크닉을 배워서 뜻깊었다..
