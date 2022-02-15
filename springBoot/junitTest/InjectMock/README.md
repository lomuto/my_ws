# InjectMock   
   
Mockito를 사용하다보면 뭐에는 `@Mock`이 붙는데 뭐는 `@InjectMock`이 붙는다.   
   
구분은 간단하다.   
`@Mock` 을 통해 껍질뿐인 bean을 생성하고 `@InjectMock`을 통해 껍질뿐인 bean들을 주입해야 할 개체를 선정한다.   
   
``` java
@Mock   
FooRepository repository;   
   
@Mock
BarService barService;

@InjectMock
FooServiec service;
```   
   
이런 테스트 코드는   
   
``` java
@RequiredArgsConstructor
@NoArgConstructor
public class FooService {
    private final FooRepository repository;
    private final BarService barService;
}
```   
   
이런 클래스에서 도는 테스트이다.