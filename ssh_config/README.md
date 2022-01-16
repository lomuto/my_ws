# SSH Configuration process
   
집에서 안쓰는 젯슨나노를 서버로 쓰려고 원격에서 접속할 수 있게 ssh 설정을 하면서 겪은 트러블 슈팅 기록.   
   
- key pair 생성   
  `$ ssh-keygen` 으로 비대칭 키 페어 생성. `.pub` 으로 끝나는게 공개키고 나머지 하나가 비밀키   
     
- 클라이언트   
  1. `$HOME/.ssh` 으로 매핑된 경로에 비밀키를 위치
  2. `$ scp ${공개키의 절대경로} ${remote host 이름}@${remote host ipaddr}:${공개키 이름}` 으로 클라이언트에서 원격으로 공개키를 등록.   
    `$ ssh-id-copy` 는 connection refuse되거나 temporaraily unavailable 떠서 관뒀음   
   
<br/>

- 서버   
  `/etc/ssh/sshd_config` 보안을 위해 파일을 다음과 같이 수정
  ``` conf
  # 기본 port는 22로 되어있지만 브루트포스 방지를 위해 수정 권장
  Port 22120

  # 세션을 종료하도록 설정. (ClientAliveInterval * ClientAliveCountMax) sec
  ClientAliveInterval 600
  ClientAliveCountMax 3

  # root login은 무조건 허용하지 않는게 좋음...
  PermitRootLogin no

  # 비밀번호 대신에 공개키 인증방식으로
  # 비밀번호 사용을 해제하기 이전에 사전에 공개키 등록을 마치는걸 권장
  PubkeyAuthentication yes
  PasswordAuthentication no

  # 최대시도횟수. default 6
  MaxAuthTries 3

  # 로그인창 대기 만료 시간. default 2m
  LoginGraceTime 2m
  ```