# 큰 수 만들기

[https://www.acmicpc.net/problem/16496](https://www.acmicpc.net/problem/16496)

주어진 수들을 합쳐서 하나의 수를 만들 떄 가장 큰 경우의 수 출력

```
3 30 9
```

자릿수가 클 수록 수 자체가 크면 큰거니까 9가 맨 앞에 오는건 금방 알지만 30,3 같이 애매한것들 처리하는게 어려웠던 문제.

`330 > 303` 이므로 무조건 큰 수로 정렬하는건 안됨.

복잡하게 생각할 것 없이 **큰 수는 큰수들의 조각의 합 이므로**

```cpp
bool cmp(string a,string b){
    if(a[0] == b[0])
        return a+b > b+a;
    else
        return a > b;
}
```
