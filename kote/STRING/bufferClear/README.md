# 첫 글자를 대문자로

### [https://www.acmicpc.net/problem/4458](https://www.acmicpc.net/problem/4458)

줄마다 문장 받아서 첫글자 대문자로 바꾸는거.

fgets 비슷하게 코드 작성하면 됨. (getline)

간단한 문제지만 여기서 굳이 쓰는 이유는...

**Buffer Clearing** 때문

처음에 줄의 수 `N`을 입력받는데, 이 때 표준입력버퍼에 `'\n'` 이 남게됨. 그러면서 처음으로 입력되는 문자잉 씹히면서 n개의 문장이 아닌 n-1개의 문장만 입력받는 오류 발생.

```cpp
cin.ignore(__INT_MAX__,'\n');
```

을 통해 개행문자 만날때까지, 개행문자를 포함해서 버퍼를 비워줌.

`__LONG_LONG_MAX__` 라고 따로 최대수가 정의되어있지만 invalid type warning 떠서 int로 바꿈.
