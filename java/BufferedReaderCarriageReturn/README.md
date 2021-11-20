# BufferedReader 사용 시 넣어주는 쪽에서 주의할점.

일반적인 InputStream은 한 단어씩 읽어온다.  
하지만 BufferedReader는 input을 버퍼링하고 한줄을 띠어서 줌으로써 한글자 씩 읽어올때 생기는 오버헤드를 어느정도 줄인 stream reading 방식이다.

**문제는 BufferedReader에서 읽을 시 write 해주는 쪽에서 carraige return(line seperator)가 없으면 block이 생긴다는점...**

BufferedReader는 **stream에서 new line character를 만날 때 까지 loop에서 character를 계속 읽어온다.**

```java
writer.write(message.toCharArray());
// writer.write(System.lineSeparator()); 이거 안해주면 읽는쪽이 bufferedReader면 한줄을 다 못읽고 newline character를 기다린다
writer.flush();
```

위와 같이 쓰면 안되고 BufferedReader로 받아줄 것 같으면 개행문자를 꼭 넣어주자...

아니면 읽는쪽이 BufferedInputStream 써서 한글자씩 떼오는거도 하나의 방법임...
