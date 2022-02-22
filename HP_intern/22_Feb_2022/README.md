# 22 Feb 2022   
   
## MockServer는 감동이다

``` kt
every { deviceGenClient.post() } returns bodyUriSpec
every { bodyUriSpec.contentType(any()) } returns bodySpec
every { bodySpec.bodyValue(any()) } returns headerSpec
every { headerSpec.retrieve() } returns response
every { response.onStatus(any(), any()) } returns response
every { response.bodyToMono(String::class.java) } returns Mono.just("hello")
```   
   
WebClient를 모킹하려면 이걸 맨날 해줘야 한다.   
근데 문제는 여기서 에러를 던지고 싶다면 어떻게 할지 감이 안온다는거...   
그래서 `MockWebServer`를 도입했다.   
   
``` kt
// Test Class

/*
    implementation 'com.squareup.okhttp3:okhttp:4.9.3'
    testImplementation 'com.squareup.okhttp3:mockwebserver:4.9.3'
    의존성 추가
*/
val mockServer = MockWebServer()
val mockServerPort = 8081

private val deviceGenClient: WebClient = WebClient.builder().baseUrl("http://localhost:${mockServerPort}").build()
    private val deviceApiClient: WebClient = WebClient.builder().baseUrl("http://localhost:${mockServerPort}").build()

@BeforeEach
fun setUpServer() {
    mockServer.start(mockServerPort)
}

@AfterEach
fun closeServer() {
    mockServer.shutdown()
}

@Test
fun createDeviceTest() {

    mockServer.enqueue(MockResponse().setBody("hello"))


    val data = deviceGenService.createDevice(DeviceAttributeDto()).block();
    assertThat(data).isEqualTo("hello");
}
```   
   
Test 코드를 작성할 클래스에 다음과 같이 필드 선언을 해준다. port 번호는 아무거나 해도 된다.   
   
BeforeEach, AfterEach 각각에 서버를 시작하고 꺼주며   
내부에는 서버의 응답을 명시해준다.   
   
이러고 돌리면 끝이다.. 완전 쉽다
    
``` kt
 mockServer.enqueue(MockResponse()
    .setResponseCode(400)
    .setBody("400 error")
)

assertThatThrownBy { deviceGenService.createDevice(DeviceAttributeDto()).block() }
    .isInstanceOf(SimulatorException::class.java)
    .hasMessageContaining("400 error")
```   
   
이렇게 에러처리에 대한 검증또한 간단하다...   
   
## 코틀린 인터페이스 inline 에서 구현하기   
   
Foo 라는 인터페이스의 구현체를 리턴하는 함수 `method` 가 있다고 해보자.   
이 Foo가 `bar` 라는 메소드를 강요할 때   
   
``` java
public Foo method() {
    return Foo() {
        @Override
        public void bar() {
            ...
        }
    }
}
```   
   
자바는 이렇게 쓴다.   
코틀린은??   
   
``` kt
fun method(): Foo = object: Foo {
    override fun bar(): Unit {
        ...
    }
}  
```   
   
문법이 좀 특이하다. 어쨋든 object를 통해 인터페이스의 구현체를 inline으로 만든다 보면 될 것 같다.   
   
## 동일 타입 이름이 다른 bean   
   
`expected single matching bean but found 4` 라는 오류를 만났다.   
무슨말인고 하니 주입해주려고 보니까 타입이 같은데 이름이 달라서 뭘 주입해야하나 모르겠다.. 이런뜻   
   
Constructor 가 아니라 `@Autowired`로 Setter 주입을 해주면 type이 같아도 이름대로 알아서 넣어준다고 한다.   
   
`@Autowired`에서 생서자 주입으로 갈아타다가 생긴 문제.     
   
## Circular Dependency   
   
CORS 관련 config bean을 Sercurity config 클래스 안의 bean으로 설정했는데 (security 관련 코드를 하나로 모으고 싶어서) circular dependecy 가 발생했다.    
   
CORS 빈을 다른 클래스에서 설정해주니 해결
