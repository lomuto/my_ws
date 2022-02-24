# 24 Feb 2022   
   
## Mockk   
   
[https://notwoods.github.io/mockk-guidebook/](https://notwoods.github.io/mockk-guidebook/)   
여기 정리가 너무 잘 되어 있다.

   
Mockk 는 kotlin 에서 지원하는 mock 라이브러리 이다.   
   
- @Mockk, mockk
  ``` kt
   @Mockk
   lateinit var foo

   val foo = mockk<Foo>()
  ```   
     두 방법으로 생성 가능하다.  
       
- every   
  ``` kt
    every { foo.doSomething(any()) } returns "ret"
  ```   
  every 를 통해 mock 개체의 stub을 설정해줄 수 있다.   
     
- answer   
  ``` kt
    every { repository.save(any()) } answer { call ->
        List<Any> args = call.invoacation.args[]
        ...
    }
  ```   
  every {} answer {} 에서 넘어온 인자값에 따른 행동 설정을 해줄 수 있다.