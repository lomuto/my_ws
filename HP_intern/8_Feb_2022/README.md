# 8 Feb 2022   
   
## Spring Security CSRF   
   
왠지는 모르겠는데 Controller에 `RquestMapping` 박아놓고 밑의 POST 엔드포인트에 `@PostMapping("/...")` 으로 추가 경로 설정 안해주면 csrf 씹힘... `http.csrf().disable()` 해도 그럼.    
   
## CORS PROXY...   
솔직히 프로젝트 처음 시작할 때 프론트에서 다 호출하면 되는 줄 알았는데 저거 두마리때문에 백엔드 사이즈가 점점커지고 있다.   
proxy는 해결했는데 지금 토큰요청하니까 CORS 걸려서 토큰 생성하는 엔드 포인트를 또 만들어야 한다.    
이왕 이렇게 된거 토큰 db에 저장하고 expire 시간 나오니까 저거로 토큰 캐싱하는 기능 구현해봐야겠다