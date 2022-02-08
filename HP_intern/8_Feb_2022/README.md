# 8 Feb 2022   
   
## Spring Security CSRF   
   
왠지는 모르겠는데 Controller에 `RquestMapping` 박아놓고 밑의 POST 엔드포인트에 `@PostMapping("/...")` 으로 추가 경로 설정 안해주면 csrf 씹힘... `http.csrf().disable()` 해도 그럼.    
   
