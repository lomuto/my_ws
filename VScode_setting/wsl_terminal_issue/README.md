# WSL 터미널 실행 안되는 이슈

```
The terminal process "C:\WINDOWS\System32\wsl.exe '-d', 'Ubuntu-20.04(기본값)'" failed to launch (exit code: 4294967295).
```

![img](./img.png)

WSL 이 업데이트를 하면서 지 멋대로 경로명에 한글을 박아놔 VSCODE에서 경로를 재대로 읽지 못해 터미널이 안 열리는 이슈가 있었다.

`Select Default Terminal` 항목에서 위 사진처럼 한글이 있는 terminal의 맨 오른쪽 톱니바퀴를 누르면 이름 변경이 가능하다.

한글을 다 지우고 저장하면 해결된다.
