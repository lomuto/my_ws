# equals

개체의 동일여부를 따져 `boolean`을 반환하는 메소드 이다. 오버라이딩 하지 않을 경우 (구현되어있지 않을경우) 주소값을 비교해 boolean을 리턴한다.

```java
// 기본으로 구현된 equals
@Override
public void equals(Obj other) {
    return this == other;
}
```

---

내가 만든 개체의 `equals` 메소드를 정의하는 베스트 프랙티스는 다음과 같다.

```java
@Override
public void equals(Obj other) {
    // 주소가 같으면 바로 true
    if(this == other) {
        return true
    }

    // null개체거나 클래스가 같지 않으면
    if(other == null || ! (other instanceof this.getClass()) ) {
        return false;
    }

    // 내부 값 비교를 이제서야 수행
    // 같은 값이면 true, 아니면 false
    ...
}
```

---

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
