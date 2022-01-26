# 26 Jan 2022   
   
3일정도 내부 api 호출 flow를 postman으로 삽질을 했다.   
postman을 그동안 사용했을 때 10% 조차도 제대로 사용을 하지 못하고 있었음을 느꼈다...     
   
Postman의 test단계에서 `pm.enviroment.set("env_key", pm.response.json().someVar)` 와 같이 postman 으로 온 response가 json 타입으로 왔다면 바로 파싱을 해서 enviroment로 설정할 수 있는게 너무 신기했다.   