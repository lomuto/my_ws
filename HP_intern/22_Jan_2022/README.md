# 22 Jan 2022   
   
오늘은 토요일. 하지만 인턴에게 주말은 없다.   
   
## What is JWT?    
- Cookie:   
  HTTP는 Stateless하다. 따라서 유저가 홈페이지를 사용하는데 있어서 매번 로그인을 해야하는 등 번거로운 일들을 줄여주기 위해 나온게 **Cookie** 이다. Cookie는 클라이언트가 보관하고 **매 request 마다 이 쿠키를 실어서 요청을 보낸다**.   
  클라이언트에서 보관한다는 쿠키 특성 상 누군가 가로챌수가 있다. 장바구니라던지 특정 element 클릭유무 이런 정보들은 문제가 되지 않는다. 하지만 유저의 개인정보같은 민감한 정보는 문제가 된다.      
     </br>

- Session:   
  위의 문제를 해결하기 위해 나온게 Session이다. 사용자의 민감한 정보는 서버에서 따로 보관을 하되, 해당 memory와 매핑된 id를 하나 만들어서 클라이언트보고 이걸 들고 다니라고 한다. 그럼 사용자는 민감한 정보를 직접 들고 다니는게 아니라, 해당 정보에 접근할 수 있는 키값을 쿠키에 들고다니면서 요청을 하는게 **비교적** 안전하다.   
     </br>
     
- What is JWT:
  ![jwtExample](./jwtExample.PNG)   
  JWT는 크게 3 파트로 이루어진다. **Header, PayLoad, Signature**.   
  - Signature:  
  시그니처는 해시값이다. Header와 PayLoad의 Base64 암호화를 거친 문자열을 이은것에 **Server가 들고 있는 secret key를 salt쳐** Signature 라는 해시값을 만든다. 이렇게되면 서버의 secret 값을 모르면 payload를 위변조해도 시그니처가 맞지 않아 검증이 가능해진다.   
  - Header:   
  헤더는 그냥 헤더. payload 복호화를 위한 암호화 알고리즘 방식이 들어있다.   
  - PayLoad:   
  실제 정보. 각 하나의 정보를 Claim이라고 하며 key, value pair로 구성되어있다. 여러가지 Claim정보를 추가할 수 있음.   
  예시에는 없지만 iat(Issued At) 같이 생성시각, exp나 eat 같은 Expire at 과 같은 만료시간도 설정할 수 있다.   
</br>
- Advantage of JWT   
  대규모 플랫폼의 경우 하나의 유저 정보로 여러 서비스에 접근할 수 있다. 이 때 session을 사용한다면 각 서비스마다 세션을 따로 관리하거나 세션만을 관리하는 서버가 또 필요한대 전자는 사용자가 매번 다른 서비스에 접근할 때 마다 로그인 하며 각기 다른 서비스의 세션을 받아와야 하는 번거로움이, 후자는 세션을 관리하는 서버의 부담이 커진다는 단점이 있다.   
  JWT를 사용하면 위의 문제점을 모두 해결할 수 있다. 클라이언트가 하나의 JWT를 들고 여러 서비스에 요청만 보내면 되기 때문에 vv   
     
</br>   
   
   ---   

  </br>   

## MongoTemplate vs MongoRespository   
   
- MongoRespository:   
  기존에 내가 사용하던 방식. `간편함`이 최대 장점. atomic한 연산을 지원하지 않음   
  </br>
- MongoTemplate:   
  이번에 새롭게 알게 된 방식. 쿼리문을 직접 작성해야하지만 유동적이고 작업에 따라서는 `Repository`에서 기본으로 제공되는 질의보다 더 효율적으로 사용 가능     


</br>    
   
   ---   

</br>   
     
## @NotNull @NotEmpty @NotBlank   
   
TDD 해보니까 이런게 잡히네.. TDD 짱짱...   
`@Email` 로 `BaseUser` Document의 email 키값을 검증하려고 테스트 코드를 짰는데 null 값을 넣으니까 `@Email` 이 그냥 문제제기를 안한것.. 다시보니까 얘는 **null**, **empty string** 검사를 안했다.   
그래서 얘네를 잡을라고 보니까 `@NotNull` `@NotEmpty` `@NotBlank` 이렇게 비슷하면서 다른 3가지가 있더라...   
   
- `@NotNull`: 말그대로 null을 잡는 애   
- `@NotEmpty`: null을 포함한 `""` 형태의 `String` 인 빈 문자열 잡음
- `@NotBlank`: 상기 언급한 두개 + `" "` 형태의 공백 문자열까지 잡음   

그럼 `@Email` 은 누구랑 같이 써야할까?   
`" "` 과 같은 공백문자열은 `@Email` 에서 잡아주므로 `@NotEmpty`와 같이 쓰면 된다.   
   
\+ 추가   
문자열 길이 잡는 `@Size` 도 `null`은 못잡음.    
`@NotNull @Size(min = n)` 이렇게 해줘야함