# 17 Feb 2022   
   
테크리더님께서 처음으로 코드리뷰를 해주셨다. 그동안 혼자 구현하면서 헤맸던 부분이 많아서 그런지 첨언해주신 부분들이 더 잘 들어왔다.

## interface 꼭 만들어라..   
     
service layer 뿐만 아니라 Controller도 interface 만들고 impl로 구현해라. 왜?    
   
1. 가독성이 좋아진다. 스프링 5.1 부터 Controller에 붙은 어노테이션도 interface 에 붙여도 적용이 된다. `@RestController`부터 `@PathVariable`까지... impl에서는 덕지덕지 붙은 어노테이션이 없으니 로직만 깔끔하게 보이고 읽기 편하다.   
   
2. 테스트의 유연성. Mocking 할 때 interface 가져다가 모킹개체 만들기 편하다. interface 구현하는 가상의 클래스 하나만 만들면 되니깐~   
   
## Autowired 보다는 RequiredArgs   
   
Autowired는 Setter 방식의 DI이다. 그말인 즉슨 개체가 생성될때 의존하는 개체가 없어도 개체 생성은 된다는 말... **개체는 생성과 유효성을 같이 해야한다**는 내용에 위배될 수 있음. 실제 Spring이 Setter로 의존성 주입해주는데 순서가 꼬일수가 있다고 한다. 그럼 null 개체를 들고 프로그램이 돌아가고 나중에 문제가 터질수도 있음.   
`@RequiredArgsConstructor`는 final 붙은 필드들을 생성자 주입해준다. 혹여나 의존하는 개체가 bean 컨테이너에 없다면 스프링 init 단계에서 에러뱉고 종료된다.   
   
## @Value 보다는 @ConfigurationProperties로   
   
이건 내가 몰랐던거다. application.yaml의 변수들 넣어줄 때 `@ConfigurationProperties`로 클래스 변수로 넣어줄 수 있다.   
   
## @Data 남발하지 않기   
   
쓸데없는 equals hashCode toString 을 만들어버린다. 필요할때 쓰면 좋지만 저 세 메소드가 필요한 상황이 아니면 @Getter @Setter 쓰자. **@Setter도 필요할때만**