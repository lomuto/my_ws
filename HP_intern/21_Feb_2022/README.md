# 21 Feb 2022   
   
인턴의 마지막주.   
호기롭게 코틀린으로 리팩토링 한다고 했다가 영혼까지 털리고 하루종일 작업한거 restore 했다.   
코틀린 자료가 없을뿐더러 spring 코틀린 자료는 더 없다.   
공식문서도 부족하다...   
   
## 코틀린 람다   
   
``` java   
// java
methodTakesLambda( arg0 -> {
    System.out.println(arg0);
    return arg0;
})
```   
   
``` kotlin   
// kotlin
methodTakesLambda { arg0 ->
    prinrln(arg0)
    arg0
 }
```   
   
괄호를 좀 지우려고 문법을 이렇게 만든 것 같은데 처음에는 헷갈려 죽는줄 알았다.   
그래도 java에서 꼭 생기던 `(()->{})` 에서 `(){->}` 으로 딱 정리되니 함수형 프로그래밍에서는 적합한 것 같다   
   
## 코루틴 모르면 쓰지마라   
   
``` kt
override suspend fun createDevice(deviceAttributeDto: DeviceAttributeDto): String>{

        log.info("Creating device...");

        return deviceGenClient.post()
            .contentType(MediaType.APPLICATION_JSON)
            .bodyValue(deviceAttributeDto)
            .retrieve()
            .onStatus(HttpStatus::isError) { response ->
                response.bodyToMono(String::class.java)
                    .flatMap { errorMessage -> Mono.error(SimulatorException(errorMessage, response.statusCode())) }
            }
            .awaitBody()
    }
```    
   
메소드 앞에 suspend를 붙이고 `bodyToMono`가 아니라 `awaitBody`를 붙여주면 비동기처리 완성! 너무 쉬운 것 같았는데 테스트코드 작성하려고 하니 `kotlinx.coroutine.core`인가 뭔가 프로젝트 설정에 없다고 무한 징징대고 넣어줘도 징징대길래 이거때문에 코드 전체를 롤백했다.   
   
``` kt
override fun createDevice(deviceAttributeDto: DeviceAttributeDto): Mono<String> {

        log.info("Creating device...");

        return deviceGenClient.post()
            .contentType(MediaType.APPLICATION_JSON)
            .bodyValue(deviceAttributeDto)
            .retrieve()
            .onStatus(HttpStatus::isError) { response ->
                response.bodyToMono(String::class.java)
                    .flatMap { errorMessage -> Mono.error(SimulatorException(errorMessage, response.statusCode())) }
            }
            .bodyToMono(String::class.java);
    }
```   
   
`Mono<String>` 을 리턴하는거로 일단 했다. 근데 `Mono<T>`가 null을 리턴할 수 있어서 그런지 코틀린을 사용한다면 어느 레이어에서든 널처리를 해줘야 할 것 같다.    
   
## Mockk 와 함께하는 테스트   
   
mockito 의 코틀린 버전이 mockk이다.   
   
``` kt
@ExtendWith(MockKExtension::class)
internal class DeviceGenServiceImplTest {

    val bodyUriSpec: WebClient.RequestBodyUriSpec = mockk()
    val bodySpec: WebClient.RequestBodySpec = mockk()
    val headerSpec: WebClient.RequestHeadersSpec<*> = mockk()
    val response: WebClient.ResponseSpec = mockk()

    private val deviceGenClient: WebClient = mockk();
    private val deviceApiClient: WebClient = mockk();
    private val accessTokenService: AccessTokenService = mockk();

    private val deviceGenService = DeviceGenServiceImpl(deviceGenClient, deviceApiClient, accessTokenService)

    @Test
    fun createDeviceTest() {
        every { deviceGenClient.post() } returns bodyUriSpec
        every { bodyUriSpec.contentType(any()) } returns bodySpec
        every { bodySpec.bodyValue(any()) } returns headerSpec
        every { headerSpec.retrieve() } returns response
        every { response.onStatus(any(), any()) } returns response
        every { response.bodyToMono(String::class.java) } returns Mono.just("hello")


        val data = deviceGenService.createDevice(DeviceAttributeDto()).block();
        println(data)
    }
}
```    
   
자바랑 비교하면 비교적 간단한 코드로 stub 설정과 mock 테스트가 가능하다.   
코틀린으로 바꾸기 잘했다고 느낀 유일한 순간...