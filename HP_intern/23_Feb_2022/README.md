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
   
이렇게 throw 하고 controllerAdvice 에서 `WebCliemtResponseException` 핸들링 해주면 끝나더라...