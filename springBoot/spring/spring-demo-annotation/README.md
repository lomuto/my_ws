# Spring demo with Annotation   
   
- `@Autowired` 어노테이션을 통해 의존성 주입이 가눙   
- 다수의 interface 의 implementation이 존재할 때 Spring은 어느정도 inference 가 가능. 예를 들어서 변수명   
`FortuneService` interface의 implementation `HappyFortuneService` 와 `RandomFortuneService`가 있을 때 type을 `FortuneService`로 하고 변수명을 `happy~` 로 하면 알아서 전자의 implementation을 주입해
- **Why do I need no-args constructor in setter injection?**   
answer: [link](https://stackoverflow.com/questions/48410451/why-do-i-need-a-no-args-constructor-to-use-applicationscoped-beans-with-construc)   
간단히 설명하자면 Spring은 user가 작성한 코드의 Object들을 프로그램에서 사용하기 위해 일종의 프록시 개체를 생성한다.(여기서 말하는 프록시란 프로그램이 코드의 문맥에서 bean을 관리하지 않고 개체를 하나 만들어서 관리하기 위함의 프록시임) 그러다 보니 인자가 없는 생성자를 통해 프록시 개체를 생성하기 위해 no-args 생성자를 강제하는것!