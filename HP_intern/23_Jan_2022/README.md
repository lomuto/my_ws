# 23 Jan 2022   
   
이더리움을 개당 300만원 가격으로 샀다.   
세일하길래 샀는데 바닥 밑의 지하실을 구경중이다   
   
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
