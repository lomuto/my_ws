# 23 Feb 2022   
   
## webClient의 비동기 에러 처리   
   
``` kt
.awaitExchange<List<ProgramIdLocalDto>> { response ->
    if (response.statusCode().value() >= 204) {
        response.bodyToMono(String.class)
            .flatMap { error -> Mono.error(SimulatorException(error, response.statusCode())
        }
    }
    ...
```   
   
동기식으로 작성한 코드를 이렇게 바꿔봤다.   
이렇게 하니 await 다음에 doNext 가 없다고 에러가 나더라.   

``` kt
.awaitExchange<List<ProgramIdLocalDto>> { response ->
    if (response.statusCode().value() >= 204) {
        throw response.createExceptionAndAwait()
    }
}
```   
   
~~이렇게 throw 하고 controllerAdvice 에서 `WebCliemtResponseException` 핸들링 해주면 끝나더라...~~   
   
``` kt
.awaitExchange<List<ProgramIdLocalDto>> { response ->
    if (response.statusCode().value() >= 204) {
        val errorResponse = response.createExceptionAndAwait()
        throw CustomException(errorResponse.responseBodyAsString, errorResponse.statusCode)
    }
}
```   
   
이렇게 기다렸다가 에러 응답을 받아서 커스텀한 예외로 던질 수 있다.   
이렇게 해야지 의존하는 서버의 에러 메세지를 제대로 보여줄 수 있음
  
## List\<List<String\>\> 의 함수형 프로그래밍으로 Set\<String\> 으로 바꾸기   
   
기존의 동기 코드를 비동기로 처리하니까 동기적으로 받은 response에서 set\<String> 으로 바꿔주던걸 함수형으로 처리해야 했다.   
   
``` java
List<ProgramLocalDto> dtos = // sync fetch

// 위에를 비동기로 처리하면 아래가 null 값으로 있는 dtos 처리해서 에러남

HashSet<String> set = new HashSet<>();

dtos.forEach(dto -> {
    dto.getSupportedCountryList().forEach(country -> {
        set.add(country.toLowerCase(Locale.ROOT));
    });
});

return new ArrayList<>(set);
```   
   
어찌어찌 함수형 공부해서 다음과 같이 처리했다   
    
``` kt
return webClient.get()
    ... // async fetch header
    .awaitExchange<List<ProgramLocalDto>> {resonse ->
        response.awaitBody()
    }
    .map { programLocalDto ->
        programLocalDto.supportCountryList.map { country ->
            country.lowercase(Locale.ROOT)  // 소문자로
        }
    }.reduceRight { accu, s -> accu + s }   // list들 하나로 합치기
    .toSet()    // 중복제거
    .toList()   // 리스트로
```