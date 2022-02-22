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