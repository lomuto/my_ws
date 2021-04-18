# JadenCase 문자열

[https://programmers.co.kr/learn/courses/30/lessons/12951](https://programmers.co.kr/learn/courses/30/lessons/12951)

```
JadenCase란 모든 단어의 첫 문자가 대문자이고, 그 외의 알파벳은 소문자인 문자열입니다. 문자열 s가 주어졌을 때, s를 JadenCase로 바꾼 문자열을 리턴하는 함수, solution을 완성해주세요.
```

- 문자열 s를 stringstream 으로 `>>` 로 받아버리면 공백처리가 까다로움. s전체를 도는 for문에서 case 나누는게 훨씬 편하다.

> 1. 문자열의 첫번째 단어거나 이전에 공백이 있던 단어거나
>    `if( !i && s[i-1] == ' ' )`
>
> 2. 숫자거나 아니거나
