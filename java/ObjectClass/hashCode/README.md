# hashCode

Java의 모든 Object를 보면 `hashCode`라는 메소드가 있다. 이는 개체 최상위 클래스인 `Object` 클래스에 정의된 함수로써 `HashMap`이나 `HashSet`과 같은 자료구조 사용 시 key값으로 사용되는 값을 리턴하는 함수이다.

default로는 다음과 같이 구현되어있다.

```java
public int hashCode() {
    return this; // 개체 주소값 리턴
}
```

---

```java
public class Person{
    private String firstName;
    private String secondName;

    public Person(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName
    }

    ...

    @Override
    public int hashCode() {
        return firstName ^ lastName;
    }
}
```

다음과같이 `Person` 클래스의 `hashCode`메소드를 오버라이딩 했다고 해보자(물론 String 값을 xor연산하면 int가 나오지 않지만 편의상 문자 하나하나들을 xor연산했다고 가정하자...)  
이 경우 `firstName`과 `lastName`이 같지 않을 경우 같은 개체가 아니게 되지만 `new Person("Kim", "Bab")` 과 `new Person("Bob", "Kim")`은 같은 해시값을 가지므로 이에 주의해서 메소드를 오버라이딩 해야한다.
