# split으로 문자열 자르기

[https://stackoverflow.com/questions/69820678/blank-splited-string-in-java-string-split](https://stackoverflow.com/questions/69820678/blank-splited-string-in-java-string-split)

스택오버플로에 질문을 올렸는데 user~~ 라는 닉네임의 친구가 답변이 아닌 댓글로 괜찮은 풀이를 공유해줬다.

```
문자열
"(B,C) (D,E) (A,B)"
를
[B,C,D,E,A,B]
로 자르기
```

```java
String str = "(B,C) (D,E) (A,B)";
String[] tokens = str.replaceAll("[(), ]", "").split(""); // `[` `]` `,` 빈칸 이렇게 4개의 문자에 대해 전부 공백으로 교체하고, 공백에 대해 split.
```
