# 파일명 정렬

[https://programmers.co.kr/learn/courses/30/lessons/17686](https://programmers.co.kr/learn/courses/30/lessons/17686)

---

스코페에 나왔던 정렬문제랑 똑같은 문제.  
저번에는 주어진 자료들을 구조체에 깔끔하게 담아서 정리하는 방법이랑 조건부 정렬에 막혔다면 이번에는 저번같은 실수 안하고 30분내에 잘 풀었다.

- pair를 활용한 구조체  
  문자열 하나에서 `HEAD`와 `NUMBER` 추출한 후, 정보들의 조건에 따라 원본을 정렬해 출력해야 하므로 `pair<string, pair<string, int>>` 과 같이 `[원본, [HEAD, NUMBER]]` 를 하나의 구조체 담아서 구조체를 정렬.  

- pair의 배열  
  긴가민가 했었는데 `pair<string, pair<string, int>> FILES[1001];` 이렇게 pair 의 배열 선언 가능하다.

- flag를 활용한 segmentation  
  `foo010bar020.zip` 과 같이 `foo` HEAD와 `010` NUMBER를 가지고 나머지 뒷단은 TAIL로 쓰레기값을 담아둔 파일명도 존재.  
  문자열->숫자->문자열 이런 순서이므로 **flag가 초기값일때 문자열을 받게하고 숫자를 받을 때 flag를 변경처리. 숫자를 지나서 문자가 나올 떄 flag는 초기값이 아니므로 반복문 종료**

```cpp
int flag = 0;
        for (int i = 0; i < buf.size(); i++) {
            if (isdigit(buf[i])) {
                flag = 1;
                NUM += buf[i];
            } else if (!flag) {
                HEAD += buf[i];
            } else
                break;
        }
```

- 대소문자를 고려하지 않는 문자열 비교 `strcasecmp`  
  `MUZI`랑 `muzi` 랑 동일한 문자열로 본다는 조건이 있음. 일반적인 `strcmp`나 string class의 대소비교는 대문자가 있는 문자열이 더 크다고 나옴.  
  **strcasecmp 는 대소문자 비교 않고 문자로만 문자열 대소비교.**  
  strcasecmp는 **const char\*** 를 parameter로 받으므로 `str.c_str()` 해서 인자값 줘야함  

- **stable_sort**  
  갓갓 stable_sort. 조건이 다 같을 떄 입력순으로 정렬하세요~ 이런말 있으면 **stable_sort** 꼭 쓰자.
