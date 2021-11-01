# toString

```java
System.out.println(obj);    // className@ 29fsjkGj2
```

아무 개체 하나 집어서 출력해보면 다음과 같이 나오는걸 볼 수 있다. 이건 `toString`이 기본적으로 클래스 이름에 골뱅이를 붙여 `hashCode`를 출력해주는것 을 오버라이딩 해놨기 때문에 그렇다.

```java
@Override
public String toString() {
    return new String(this.getClass().getName() + "@" + Integer.toHexString(hashCode()));
}
```

오버라이딩 해서 정해진 문자열을 리턴하게 구현하면 표준출력에 문자열을 출력해주는 함수의 인자로 넣으면 그게 출력된다^^
