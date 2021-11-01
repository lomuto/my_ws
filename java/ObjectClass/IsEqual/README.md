# 개체의 비교

Java에서 제공되는 `String` 클래스는 `==`으로 비교하면 주소(참조)값 비교니까 문자열을 비교하려면 `.equals(String)` 메소드 쓰는건 누구나 안다...

Generic을 이용한 클래스같은 경우 `Object<int>` 가 안된다. 제너릭에 들어가는건 개체 type이여야 하므로 `Object<Integer>` 이어야 한다.

이제 여기서 문제가 생긴다...

저 Object안의 값을 빼왔을 때 그 안의 값은 당연히 **int 와 같은 원시 타입이 아니라 Integer인 개체 타입이다.** 근데 웃긴건 자바에서 **Integer 개체의 정수값들 중 -128 ~ 127은 캐싱을 해줘서 `==` 연산자로 비교가 된다는 거다**

```java
Integer a = new Integer(1);
Integer b = new Integer(1);

System.out.println(a == b); // true

a = new Integer(100000000);
b = new Integer(100000000);

System.out.println(a == b); // false
```

마지막 두 a와 b같은 애들은 `equals` 해줘야지 true가 나온다.
