# Spring demo with Annotation   
   
- `@Autowired` 어노테이션을 통해 의존성 주입이 가눙   
- 다수의 interface 의 implementation이 존재할 때 Spring은 어느정도 inference 가 가능. 예를 들어서 변수명   
`FortuneService` interface의 implementation `HappyFortuneService` 와 `RandomFortuneService`가 있을 때 type을 `FortuneService`로 하고 변수명을 `happy~` 로 하면 알아서 전자의 implementation을 주입해줌