# string::insert

문자열 중간에 문장 삽입 메소드.

```cpp
string s = "Hello";
s.insert(0,"good");
cout << s;  // goodHello
s.insert(2,"zz");
cout << s;  // gozzodHello
```

문자열의 원본을 수정함에 주의. 수정된 문자열을 return 하고 원본은 유지하는게 아니다.

문자 하나를 추가하더라도 `insert(n,"a")` 이렇게 해야지 `insert(n,'a')` 이렇게 하면 오류난다.
