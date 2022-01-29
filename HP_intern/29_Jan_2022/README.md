# 29 Jan 2022   
   
설날동안 코틀린 기초 문법 떼고 oauth 확실히 끝내야겠다.   
   
## Kotlin: var, val, const val   
   
Rust 는 모든 변수가 기본적으로 immutable 하다. 그래서 mutable 한 변수를 만드려면 변수 선언할 때 `mutable` 이라고 명시적으로 표시해줘야 한다고 한다. 실수를 줄여줄 수 있다는 점에서 괜찮은 언어적 기능이라고 생각한다.   
코틀린도 비슷하다. js에서 `var`와 `const`가 있듯이 코틀린에는 `var` 와 `val`이 있다.    

Kotlin은 implicit type 을 제공한다.   
`val foo = "hello"` 하면 문자열 타입으로 알아서 알아먹는다는 뜻   
`val foo: String = "hello"` 명시적 type declaration은 이렇게

`var`는 mutable한 변수이다. 물론 코틀린은 컴파일 언어이니 js처럼 타입이 바뀌고 그러지는 않는다. **값만 바뀌지 type은 고정**   
   
`val`은 java의 `final`과 거의 똑같다.   
``` kt
val arr = listOf(1,2,3)   
arr = listOf(1,2,3) // comple error
arr.add(5)  // legal
```   
변수에 할당된 메모리 주소를 바꿀 수 없다. 그래서 다른 변수값을 집어넣을수는 없지만, collection 같은 경우 주소값은 그대로지만 안의 원소들은 추가할 수 있다.   
   
`const val` val이면 val이지 const val은 뭐지 하고 헷갈렸다.   
Kotlin은 static이 없다. 그래서 파일 상단에   
``` kt
const val foo = "Hello"

class Bar {...
}
```
를 하면 foo를 전역적으로 접근할 수 있다.   
`val`과 마찬가지로 immutable하지만 **변수에 할당되는 값이 컴파일 타임에 알 수 있는 literal 이어야 한다.**   
   
``` kt 
const val foo = "hello" // 컴파일타임에 컴파일러가 무슨값인지 알 수 있음   
const val bar = readLine()  // 컴파일 타임에는 표준출력의 메모리 주소도 안정해져 있다. 이거는 런타임 때 알 수 있는 값이므로 complie error   
   
...   
   
val baz = readLine()    // 이거는 런타임 때 immutable 하게 관리하면 되므로 ok
```