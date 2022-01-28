# 28 Jan 2022   
   
Postman Collection을 어제 거의 다 마무리 지었다.   
주말부터는 구현에 들어갈 수 있었으면 좋을 것 같다.   
   
## REST API란   
   
보통 RESI API란 HTTP 메소드와 URI 리소스를통해 리소스를 요청, 추가, 수정 또는 삭제한다 정도로 알고있는데 이거는 **HTTP API** 에 그칠 수 있는 설명이라고 한다. REST API가 되기 위해서는 적어 두가지가 더 필요하다.   
   
### Self Descriptive   
   
메세지 스스로가 자신에 대한 설명을 포함하고 있어야 한다는 뜻.  
즉 응답이 왔을 때, 본문에 해당 API 에 대한 설명(문서)이 있어야 한다는 뜻. html 페이지 전체를 넣을수는 없기때문에 최소한 링크는 있어야함.   
   
### HATEOAS (Hypermedia As The Engine Of Application State)   
   
위에서 메세지가 Self descriptive 해야 한다고 했는데 이게 여기서 충족이 된다. 응답에 리소스 또는 다음 주소로의 링크를 넣어줘야한다는 뜻. 이렇게 하면 api 버전을 명시하지 않아도 되고 링크를 통해 상태전이가 쉽다는 장점이 있다.