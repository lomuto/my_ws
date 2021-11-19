# End of stream in socket connection

간단하고 귀여운 echo client, server 프로그램을 socket 으로 작성한다 해보자.

```java
// Client
BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
BufferedWriter writer = new BufferedWriter(new InputStreamWriter(socket.getInputStream()));

String message = "Message from Client";
message += System.LineSeperator();

// 1. Server에게 메세지 전송
writer.write(message.toCharArray());
writer.flush(); // flush 꼭 해주기

// 3. Server로부터 내가 보낸 메세지 그대로 역수입
String buffer
while((buffer = reader.readLine()) != null) {
    ...
}
```

```java
// Server
BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
BufferedWriter writer = new BufferedWriter(new InputStreamWriter(socket.getInputStream()));

// 2. Client 와 연결된 Socket에서 읽어들인 문자열 그대로 전송
String buffer
while((buffer = reader.readLine()) != null) {
    writer(buffer.toCharArray());
}
writer.flush(); // flush 꼭 해주기
```

이걸 실제로 돌려보면 Server에서 문자열 처리하는 loop에서 thread가 block된다.

[https://stackoverflow.com/questions/15521352/bufferedreader-readline-blocks](https://stackoverflow.com/questions/15521352/bufferedreader-readline-blocks)

여기 글을 잘 보면 알겠지만, **BufferedReader는 stream이 닫힐 때 까지 개행 문자로 stream에서 문자열 끊어서 계속 읽어들인다.**  
이말인 즉슨 socket이 닫히기 전까지 loop 탈출을 못해서 thread가 막힌것...

Client로부터 개행문자 하나로 문자열의 끝을 알려주려면

```java
while(reader.ready() && (buffer = reader.readLine()) != null) {
    writer(buffer.toCharArray());
}
```

이렇게 `ready`상태를 확인해주던가

```java
BufferesInputStream is = new BufferedInputStream(socket.getInputStream);

int c;
while(c = is.read()) {
    if(c == '\n') {
        break;
    }
    ...
}
```

이렇게 한글자씩 빼오다가 개행문자를 만나면 종료해버리면 된다.
