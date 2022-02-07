# 6 Feb 2022   
   
## 프론트에서 포워드 프록시 서버를 거쳐 요청을 보낼 수 있는가...?   
   
java에서는 HTTPClient 클래스를 통해 프록시 인스턴스를 client 클래스 생성 시 추가 후 Request 클래스를 별도로 생성해 `send` 메소드의 인자로 넣어줌으로써 존재하는 프록시 서버를 `agent`로 요청을 라우팅 할 수 있다.   
근데 react에서 똑같은 일을 구현하려고 보니 자꾸 오류가 나며 되지 않았다...   
결국 스프링 백엔드를 하나 띄워놓고 이를 프록시 처럼 사용해 프론트에서 요청을 보내고 있는데 어찌저찌 문제를 해결하긴 했지만 **정말 프론트에서는 프록시 서버를 라우팅해 요청을 보낼 수 없는건지** 궁금하다. 자바는 됐으니까 얘도 될 법 한대...   
   
## Java OpjectMapper   
   
자바 클래스를 하나 생성해 이를 json 형식의 string으로 변환해 전송하기.   
``` java
ObjectMapper mapper = new ObjectMapper();
Foo foo = new Foo();

mapper.writeValueAsString(foo); // json string format
```   
   
이렇게 하면 json 형식의 string 이 리턴된다.