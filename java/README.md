# java

자바는 초기에 임베디드 환경을 고려해 제작된 언어이다.

자바는 `Cross Platform` 언어일까?  
반은 맞고 반은 틀리다.

C언어는 `전처리->컴파일->어셈블러->링킹` 단계를 거쳐 executive 한 실행파일로 코드가 컴파일된다.  
문제는 Linux,Window,Mac 별로 고유의 실행파일 형태가 있어 Window에서 컴파일한거는(`a.exe`) 리눅스에서는 실행 못한다(`a.out`)

Java는 컴파일의 결과물이 실행파일이 아닌 `Byte Code`이다.  
그리고 **`Java Virtual Machine`** 은 이 `Byte code`를 운영체제에 맞게 interpret (최신 jvm은 `JIT`를 지원한다.) 해 작업을 수행한다.

이런이유로 완벽한 `Cross Platform`이라고 하기에는 어폐가 좀 있다ㅎㅎ
