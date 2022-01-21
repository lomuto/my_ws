# 21 Jan 2022   
   
- Google 이용한 OAuth 구현 했음   
- SpringSecurityConfig 에서 시큐리티 관련 Config 를 진행하는데 빌더패던으로 진행됨. 여기서 `antMatchers` 를 통해 인증에 따른 진입점 그리고 인가 (ROle) 에 따른 진입 가능여부 다르게 설정할 수 있음   
- application.yaml or properties 에서 `spring.security.oauth2.client.registration.google.scope` 설정 안해주면 OAuthServie가 통으로 실행이 안되더라 **개빡치는건 로그인은 돼서 인증은 넘어감** 왜인지 이유를 찾아보자..