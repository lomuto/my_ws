# SpringBootTest   
   
@SpringBootTest 를 통해 테스트를 실제 스프링이 구동되는 환경에서 진행할 수 있다.   
   
하지만 이렇게 테스트를 진행할 경우 테스트에 필요한 환경 이외에 전체 환경이 로딩되므로 느리다.   
   
이를 보완하기 위해 나온게 `Mockito`이지만 Mock을 생성하고 application.properties 와 같은 곳에서 `@Value`를 통해 문자열을 주입받을수 없기에 `ReflectionTestUtils.setField` 을 통해 하드코딩이 필요하다. (Mock은 껍데기이기 때문에)   
   
이런 상황에서는 `@SpringBootTest(classes = {AccessTokenService.class})` 와 같이 특정 클래스를 위한 bean을 스프링 환경을 구동해줄 수 있다.   
   
주의해야할게 `@SpringBootTest(classes = {fooRepository.class})` 와 같이 repository 빈을 등록할 수 있을까? **코드로는 Repository 인터페이스 상속하는거로 클래스 선언이 끝나지만 Under the hood에서 여러가지 의존성을 Spring이 주입해준다** 그말인 즉슨, 저 클래스 하나로 온전한 repository 클래스 bean 등록이 불가능 하다는 것. 그래서 보통 repository는 `@Mock` 또는 `@MockBean` 을 통해 테스트를 진행해야한다.