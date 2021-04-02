# 울타리 칠하기

문제: [https://codeforces.com/problemset/problem/448/C](https://codeforces.com/problemset/problem/448/C)

스택오버플로우에 질문 올린거: [https://stackoverflow.com/questions/66914039/wa-in-codeforces-448c-what-are-the-flaws-in-my-logic](https://stackoverflow.com/questions/66914039/wa-in-codeforces-448c-what-are-the-flaws-in-my-logic)

---

대표적인 분할-정복 문제

각각의 길이가 전부 다른 막대기들이 붙어있을 때  
최소로 칠하는 수를 구하는거.

이분탐색이랑 concept 자체가 매우유사해서 아이디어 떠올리는건 얼마 안걸렸는데 issue가 하나 있어서 오랫동안 헤맸고 문제는 풀었지만 처음에 틀린건 왜 틀린건지 아직 모른다.

---

임의의 segment `[st,end]` 에서 `(막대기의 길이의 최소) >= st-end` 이면 세로로 칠하는게 더 효율적이다.

이 idea에 착안해서 `if(막대기의 길이의 최소>= st-end)` 이면 `st-end` 를 return 하게 했는데 이렇게 하면 원래 답보다 더 많은 수가 나온다.

해결방안은 세로로 칠하는 경우의 수인 `vertical` 과 재귀호출을 통해 가로로 칠하는 경우의 수를 구하는 `horiziontal += DC(st,end)` 이 두개를 비교한 값 중 더 작은값을 최종적으로 return 하게 하면된다.  
직관적으로 봐도 두번째 풀이가 논리적으로 맞지만 처음에 내가 생각한 방식에 어떤 예외 case가 있는지 알고싶다.
