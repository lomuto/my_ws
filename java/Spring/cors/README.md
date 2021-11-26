# CORS in Spring boot

CORS는 프론트와 백간의 약속 같은거다.  
프론트에서 서버로 요청을 보내고, 백은 요청에 응답을 할 때 CORS정보를 담아서 수신하는데, 이 때 백에서 보낸 응답에 프론트의 url주소의 정보가 없으면 수신을 거절하게 된다.

Spring 에서는 이를 설정할 수 있는 간편한 두가지 방법이 있다.

<br/>

**프론트에서 서버에 요청을 보낼 때 protocol을 빼먹지 마라!**

`www.server.com` 에서는 cors 뜨던게 `http://www.server.com`에서는 안뜨더라... 프로토콜 빼먹지 말자

---

## 1. Controller에 설정

```java
@RestController
@RequestMapping("/api/foo")
@CrossOrigin(name = "www.frontURL.com")     // 여기에 추가해 아래의 모든 Controller에 붙일수도
public class FooController {

    ... // Service 의존성 주입과 생성자

    @GetMapping("/getFoo")
    @CrossOrigin(name = "www.frontURL.com")     // 여기에 해당 Controller에만 붙일수도있다
    public ResponseEntity<Foo> getFoo(){
        ...
    }
}
```

---

## 2. 전역적으로 설정하기

```java
@Configuration
public class WebConfig implements WebMvcConfigurer {
    @Override
    public void addCorsMappings(CorsRegistry registry) {
        registry.addMapping("/**").allowedOrigins("*");     // allowedOrigins에 주소 추가
    }
}
```
