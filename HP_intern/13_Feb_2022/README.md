# 13 Feb 2022   
   
## 204 는 200번대 에러다   
   
HttpClient 로 프록시 클라이언트를 생성하고 이거로 요청을 보냈다.   
얘는 restTemplate 같이 자동으로 에러처리를 안해줘서   
`if(response.statusCode() >= 300)`    
으로 에러처리를 했는데 `204`가 리턴되었다.   
나는 응답에는 문제가 없다고 가정하고 응답을 ObjectMapper 로 파싱했는데 여기서 에러가 나길래 왜 에러가 안나나 했다   
원인은 프론트에서 base64로 인코딩한걸 디코딩 안하고 바디에 실어 넣어서..   
바디값이 문자열이 아니라 인코딩 된 값이 넘어가니까 읽지를 못해서 204를 리턴했는데 이걸 못잡았다.   
204처리를 하던가 디코딩을 하던가.. 둘 중 하나라도 했으면 안 이랬을텐데ㅠㅠ