# @Mock and @MockBean
    
@Mock 은 꼭 `@ExtendWith(MockitoExtension.class)` 와 함께 사용되어야 하고 @MockBean은 `@ExtendWith(SpringExtension.class)` 와 쓰이는 기능이다.   
   
둘 다 껍질뿐인 가상의 개체를 생성해준다.   
즉, 의존성이 발생하는 부분에서 이게 주입만을 도와주고 **해당 개체의 필드나 메소드는 설정을 해주어야 한다.**