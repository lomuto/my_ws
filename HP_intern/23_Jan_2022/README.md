# 23 Jan 2022   
   
이더리움을 개당 300만원 가격으로 샀다.   
세일하길래 샀는데 바닥 밑의 지하실을 구경중이다   
   
## _IMPORTANT_ Service Layer Test With Mockito   
기존에 짰던 Service Layer 테스트는 Spring Boot Test로 실제 프로그램 구동 환경에서 테스트가 돌아가는것이어서 data base 에 실제 mock data 가 삽입되고 이걸 `@AfterEach` 로 일일이 삭제를 해주는 번거로움에 더해 **테스트 만을 위한 컨테이너 초기화가 아니라 전체 프로그램을 위한 초기화가 진행되면서 너무 무겁고 느렸다**   
이걸 어떻게 해결하지? 하면서 발견한게 **Mockito**   
test 만을 위한 bean을 초기화해줘서 굉장히 가볍고 실제 db에 쓰고 읽는 작업또한 존재하지 않는다.   
   
테스트를 위한 설정이 복잡하다.   
`@Mock` `@MockBean` `@InjectMocks` `@RunWith` `@ExtendWith` 등등 어노테이션이 너무 많고 특히 repository 관련해서 어노테이션 조합?을 잘못 쓰면 nullptr 예외뜨고 헷갈린다.   

``` java
@ExtendWith(MockitoExtension.class)
class BaseUserServiceImplTest {

    @Mock
    private static BaseUserRepository repository;

    @InjectMocks
    private static BaseUserServiceImpl baseUserService;
```   
   
우선은 이런 상황에서 에러없이 잘 돌아가는거 확인   
   
``` java
@Before
public void setUp(){
    MockitoAnnotations.initMocks(this);
}
```
   
경우에 따라서 위의 코드 넣어줘야 할때도 있었음

</br>

## Service Test 커버리지는?   
   
현재 다음과 같이 BaseUser 의 Service Interface가 정의되어 있다.   
``` java
public interface BaseUserService{

    BaseUser save(BaseUser baseUser);
    void setRoleToBaseUser(String email, String roleName);
    BaseUser getBaseUser(String email);
    List<BaseUser> getBaseUsers();
    void delete(BaseUser baseUser);
}
```    
   
여기서 Test를 할 때   
**`getBaseUser`는 dummyData를 하나 생성해 `save` 후 get을 하는 과정이라 `save`가 테스트 과정에 포함이 된다.**   
**`setRoleToBaseUser`는 심지어 `get`과 `save`모두를 포함한다**      

`setRoleToBaseUser` 테스트를 하면 get과 save 테스트는 따로 안해도 되는걸까?
   

</br>   
   
## How to prevent inserting duplicate index   
   
매번 User insert 이전에 `get` 쿼리를 통해 중복되는 index를 검사해서 save를 해야하나?   
이거밖에 방법이 없을 것 같긴 함   
제일 좋은거는 프론트 단에서 미리 검사를 해서 백단까지 못오게 하는것인가