# 20 Feb 2022   
   
## WebClient 으로 리팩토링   
   
``` java
return deviceGenClient.post()
        .contentType(MediaType.APPLICATION_JSON)
        .body(BodyInserters.fromValue(deviceAttributeDto))
        .retrieve()
        .onStatus(HttpStatus::isError, response -> response.bodyToMono(String.class)
                .flatMap(error -> Mono.error(new RuntimeException(error))))
        .bodyToMono(String.class)
        .block();
```   
   
RestTemplate HttpRequest 를 사용하던 코드를 WebClient로 리팩토링했다.   
WebClient를 처음 봤을때 함수형 프로그래밍과 비동기 처리를 지원하다보니 이해하기 힘들었는데 이제는 읽을만 하다.   
   
`Mono`와 `Flux` 에 대해서도 간단하게 알아봤는데 둘 다 비동기 처리를 지원하기 위한 `Publisher` 추상체의 구현체이다.   
   
`Mono`는 [0,1] 이고   
`Flux`는 [0,n] 이다.

- `body` or `bodyValue`:   
  `body`는 `Publisher`를 받고 `bodyValue`는 raw object를 받는다.   
  `body(BodyInserter(obj))` 를 통해 body로 개체를 넣어줄 수 있다.   
     
- `retrieve`:   
  요청을 실행. retrieve는 응답의 body를 파싱해서 넘겨주는데 응답 전체를 보고싶으면 `exchange`를 사용해야 한다. 근데 이게 deprecated 되었고 `exchangeToMono`나 `exchangeFlux`를 사용해야 한다.   
     
- `onStatus`:
  에러처리를 담당. 첫번째 인자로 boolean 값을 리턴하는 함수를 받는다. 두번째 인자로는 response를 인자로 받는 메소드 인터페이스 구현체.   
  response의 body를 Mono로 리턴하고 안의 내용을 예외로 던진다. advicer 가 이걸 받아서 던져줌 그럼.   
     
## Mono 안에는 아무것도 없을 수 있다.   
   
bodyToMono는 `Mono<T>` 를 뱉는데 이게 안에 0 또는 1개가 들어간다. 즉 **안에 까보면 하나도 없을 수 있다.**   
그럼 이걸 어떻게 막냐   
   
`bodyToMono(String.class).single().block();` 이렇게 하면 single 부분에서 안에가 비어있으면 예외를 던진다.   
이 예외를 잡아다 처리하고 싶으면   
   
``` java
bodyToMono(String.class)
    .switchIfEmpty(Mono.error(
        new SimulatorException(
            "Null has returned from dependent service",
            HttpStatus.INTERNAL_SERVER_ERROR
        )
    ))
```   
   
이렇게 `switchIfEmpty`를 통해 별도의 예외로 처리할 수 있다.

## exchangeToMono 왜 안되냐   
   
위에서 얘기했듯 header를 확인하려면 `exchangeToMono` 를 사용해야한다.  
내가 이거로 하고싶었던건 response body에 webClient로 보낸 요청에 대한 response의 body와 header를 묶어서 json 형식으로 리턴하는것.

``` java
webClient.post()
    .uri(URI)
    .accept(MediaType.APPLICATION_JSON)
    .headers(h -> {
        h.setContentType(MediaType.APPLICATION_JSON);
        h.setBearerAuth(token);
    })
    .exchangeToMono(response -> {
        if(response.statusCode().value() >= 204) {
            // ucde에서 204 에러도 보내서 204부터 에러처리
            return response.bodyToMono(String.class)
                        .flatMap(message -> Mono.error(new MyError(message, response.statusCode())));
        }

        return new UiInfoResponseDto(
            response.headers().asHttpHeaders().toSingleValueMap(),
            response.bodyToMono(new ParameterizedTypeReference<Map<String, Object>>(){})).single().block();
        )
    })
    .single()
    .block();
```   
   
이게 함수형 프로그래밍인가? 이게 왜 좋다고들 하는지 모르겠다. 아마 내가 잘 못써서 그런거겠지   
간단히 요약하자면 요청을 보내고 에러면 예외처리를 아니면 body와 헤더를 묶어 하나의 개체로 리턴한다.   
   
**이걸 실행하면 block 안에 block이 있다고 예외가 난다.**   
   
그래서 exchangeToMono 안에 부분을 바꿔봤다   
   
``` java
var res = ...
    .exchangeToMono(response -> {
        if(response.statusCode().value() >= 204) {
            // ucde에서 204 에러도 보내서 204부터 에러처리
            return response.bodyToMono(String.class)
                        .flatMap(message -> Mono.error(new MyError(message, response.statusCode())));
        }



        return Mono.just(response);
        )
    })
    .single()
    .block();

return new UiInfoResponseDto(
            res.headers().asHttpHeaders().toSingleValueMap(),
            res.bodyToMono(new ParameterizedTypeReference<Map<String, Object>>(){})).single().block();
        )
```    
   
아예 response를 빼내고 밑에서 headers와 body로 개체를 생성시도.   
   
**골때리는게 여기서 header는 값이 정상적으로 나오는데 body가 null이 나온다.**   
`Mono.just` 관련해서 내가 모르는게 있는 것 같은데 아직도 이유를 모르겠다... 이거로 주말을 날림   
   
`return response.toEntity(new ParameterizedTypeReference<Map<String,Object>>() {});`   
   
지금은 그냥 response를 entity로 바꿔서 날림.   
이러면 header도 자동적으로 전송됨.   
   
근데 header가 또 말썽이었던게....     
   
## CORS에는 header도 있다   
   
header값이 최소한으로만 넘어오길래 postman으로 확인해보니까 여기서는 잘 넘어옴, 쎄해서 cors를 찾아보니까 cors에서 method 설정뿐만 아니라 header도 expose 해줄것들을 설정해주어야 했다.   
   
``` java
.allowedOrigins("http://localhost:3000")
    .allowedMethods("*")
    .allowedHeaders("*")
    .exposedHeaders("*");
```   
   
cors 설정에서 이거로 일단 땜빵