# 사이버 개강 총회

[https://www.acmicpc.net/problem/19583](https://www.acmicpc.net/problem/19583)

문자열 대비 특훈...

## 더이상 틀리지 말자 한줄 입력받기

- `cin.getline(char[], n, delimiter)`: 얘는 문자의 배열을 받아서 string 타입은 못씀. **str.c_str()** 해도 못쓴다.  

- `getline(fd, buffer)`: string 클래스에서 제공해주는 함수.  
  file descriptor 를 첫번째 인자로, 들어오는걸 저장할 string type의 buffer를 두번째 인자로 받는다.  


**한줄 입력 받기 이제 그만 헷갈리자..**

<br/>

주어지는 문자열의 형식이 동일하므로, `HH:MM` 형식 문자열을 분단위의 정수로 넘겨주는 함수로 시간을 끄집어냄.  
시간을 추출하는 함수는 문자열의 복사를 방지하기 위해 **const string&** 으로 해주어야함.

해시셋을 두개 두어서 출석용, 마지막 출튀 안했는지 용 두개를 둠.
