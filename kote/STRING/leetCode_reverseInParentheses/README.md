# 괄호 속 문자열 뒤집기

[https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/)

codeSignal에서 본 문젠데 거긴 lock돼있어서 leetCode에서 같은 문제로 링크 달았음.

풀면서 벽을 느꼈던 문제...

이 문제를 풀면서 배운 것

1. cpp에서 iterator를 응용한 `reverse` 함수 사용법
2. string 개체의 `replace` 메소드 사용법

나는 내가 메모리 사줄것도 아니면서 왜 자꾸 `str` -> `sappendtr` 과 같이 중간에 문자열 껴서 메모리랑 시간 늘어나는거 신경쓰는지 모르겄다...

---

기존에는  
`abc(def)`을 `abcfed` 와 같이 기존 문자열을 replace해버렸는데 solution들 보니까 더 좋은 방법이 있더라

`abc(def)` -> `abc(fed)` 해놓고 막판에 리턴하는 문자열에는 `(`이랑`)` 빼놓고 복사하기.
