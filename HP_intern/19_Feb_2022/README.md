# 19 Feb 2022   
   
## Spring security cors default 설정   
   
cors 설정을 이전에 잘 해주고 post 잘 쏘다가 갑자기 delte 하니까 cors 뜨길래 설마하고 구글링 해보니까 default 에는 `HEAD` `GET` `POST` 밖에 method allowed 설정이 안되어 있다고 한다.   
   
``` java
.allowedOrigins("http://localhost:3000")
						.allowedMethods("*");
```   
   
이렇게 allowMethods("*") 을 통해 모든 메소드 허용을 해주었다.   
만약 `.allowedMethods("DELETE")` 만 해주면 말 그대로 delete 메소드만 허용해주고 나머지는 block 되니깐 전부 해줘야한다.