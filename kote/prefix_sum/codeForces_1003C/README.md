# prefix sum

[https://codeforces.com/problemset/problem/1003/C](https://codeforces.com/problemset/problem/1003/C)

영어라서 지문 읽는게 어려웠지 간단한 구간합 브루트포스 문제.

- 변수 type 확인  
  TC max 5000 에 원소값 max 5000 이라 최대 25,000,000 으로 int type 으로 해결 가능.

- 소수점 자리 출력

```c
printf("%f.7",num);
```

C언어에서는 간단하게 소수점 자리수 출력 가능.

```cpp
cout << fixed;
cout.precision(7);
```

Cpp에서는 `fixed`로 소수점 자리수 켜주고 `precision(n)` 으로 소수점 n자리까지 출력. 까먹지 말자.
