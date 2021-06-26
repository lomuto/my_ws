# 한줄입력받기 및 eof

[https://www.acmicpc.net/problem/4358](https://www.acmicpc.net/problem/4358)

**c++에서의 공백포함 한줄입력 받기**

```cpp
string inputBuffer;
getline(cin,inputBuffer);
```

위와 같은 형태이다.

만약 저기서 eof까지 받고싶다면

```cpp
while(getline(cin,buffer)){
    //....do something
}
```

와 같이 해주면 된다.
`getline` 함수에서 eof 만날 시 null을 리턴.
