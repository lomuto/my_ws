# 오픈채팅방

[https://programmers.co.kr/learn/courses/30/lessons/42888](https://programmers.co.kr/learn/courses/30/lessons/42888)

---

`pair<string,string>` 활용해서 user id와 nickname을 합쳐서 관리하려고 한거 까지는 좋았는데

```cpp
"Enter uid1234 Muzi"
```

다음과 같은 문자열을 `stringstream` 으로 스트림화 해서

```cpp
stringstream ss.str(givenStr);
ss >> p.first >> p.second >> nickname;
```

이렇게 받아버리면 끝의 `Muzi`는 마지막에 공백이나 개행문자가 없으므로 안받아진다.

공백처리 편하게 하려고 스트람화 한거까지는 좋았는데 마지막 못받는거 생각 못하고 헤매다가 못풀었다.  
`strtok` 쓰거나 임의로 함수 만들어서 공백을 기준으로 단어 잘라서 받는 방법을 생각해봐야겠다.

---

제시된 조건에서 앞의 단어는 `Enter`,`Leave`,`Change` 이 3가지이다.  
즉 `givenStr[0] == 'E'` 했을때 참이면 `Enter`인거.

```cpp
pair<char,string>
```

형식으로 pair를 조금 더 가볍게 받을 수 있겠다.

---

`Enter`일때는 단어가 3개인데 `Leave` 일때는 단어가 두개이다.  
문제 잘 읽고 이런거 빼놓지말자...
