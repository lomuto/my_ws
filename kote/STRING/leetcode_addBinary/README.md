# 이진수 문자열 덧셈

[https://leetcode.com/explore/learn/card/array-and-string/203/introduction-to-string/1160/](https://leetcode.com/explore/learn/card/array-and-string/203/introduction-to-string/1160/)

---

</br>   
   
## 문제조건을 잘 읽읍시다.
문자열이 기본인데 내가 기본기가 좀 딸린다는 생각이 든다.   
   
**문제조건이 문자열의 길이가 최대 10^4** 라고 했다.   
   
비트필드를 활용하려고 했지만   
**최대인 unsigned long long 도 128bit이다.** 최대 길이인 1000 에는 한참 못미친다는거...   
   
```cpp
string addBinary(string a, string b) {
    int size_a = a.size();
    int size_b = b.size();

    unsigned long long *A, *B;
    A = (unsigned long long *)malloc(sizeof(unsigned long long));
    B = (unsigned long long *)malloc(sizeof(unsigned long long));
    memset(A,0,sizeof(unsigned long long));
    memset(B,0,sizeof(unsigned long long));

    for (int i = 0; i < size_a; i++) {
        *A = *A << 1;
        if (a[i] == '1')
            *A = *A | 1;
    }
    for (int i = 0; i < size_b; i++) {
        *B = *B << 1;
        if (b[i] == '1')
            *B = *B | 1;
    }
    cout << *A << '\n' << *B << '\n' << *A+*B << '\n';
    *A = *A+*B;
    int longer = size_a > size_b ? size_a : size_b;
    string ans = "";
    for (int i = 0; i < longer; i++) {
        if (*A & 1)
            ans = '1'+ans;
        else
            ans = '0'+ans;
        cout << ans << '\n';
        *A = *A >> 1;
    }
    if(*A&1)
        ans = '1'+ans;

    return ans;
    }

```

```
