# ConfigurationProperties Test   
   
application.yaml의 변수들 주입을 `@Value`에서 `@ConfigurationProperties` 로 갈아탔다.      
잘 도는지 간단한 값 테스트를 했는데 이게 왠일.. null값이 리턴되었다.   
     
``` java
@ExtendWith(SpringExtension.class)
@SpringBootTest(classes = {AuthzPropertiesConfig.class})
class AuthzPropertiesConfigTest {

    @Autowired
    AuthzPropertiesConfig authzPropertiesConfig;

    @Test
    void propertiesTest() {
        assertThat(authzPropertiesConfig.getClientKey()).isNotEqualTo(null); // fail
    }
}
```
   
왜인고 찾아보니 Spring 메인 Application에 properties 설정을 해준게 기억이 났다...   
   
``` java
@SpringBootApplication
@ConfigurationPropertiesScan(/*class path*/)
public class SimulatorApplication {
    ...
```   
   
Test 클래스에도 저 설정을 해줘야지 properties 를 읽을 수 있다... Spring 제대로 안하고 부트부터 시작해서 그런지 어이없는곳에서 헤맸다..   
   
``` java
@ExtendWith(SpringExtension.class)
@ConfigurationPropertiesScan(/*class path*/)
@SpringBootTest(classes = {AuthzPropertiesConfig.class})
class AuthzPropertiesConfigTest {
```   
   
classpath 는 `com.example.demo` 같은 패키기 path.   
`@EnableConfigurationProperties(value = Foo.class)` 와 같은 특정 클래스 타깃으로 하는 어노테이션으로 바꿔도 된다.