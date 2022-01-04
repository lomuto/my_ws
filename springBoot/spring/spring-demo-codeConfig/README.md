# Configuration with code not XML   
   
- `@Bean` 은 어따가 써먹는 녀석일까...   
: 외부 라이브러리 같은 곳에서 가져온 코드의 개체들을 Config 를 통해 Bean 컨테이너에 런타임에 등록. 이렇게 하면 외부에서 온 개체라도 `@Autowired`같은것에 사용할 수 있음. AWS S3 와의 연동을 통한 예시는 [여기](https://www.udemy.com/course/spring-hibernate-tutorial/learn/lecture/22289332#content) 서 확인 가능