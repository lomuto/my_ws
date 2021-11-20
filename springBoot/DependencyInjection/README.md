# 의존성 주입

한창 Typescrip 팔 때 Spring 하는 친구들이 하도 의존성 주입 이래서 뭘 그렇게 열심히 집어넣나 싶었는데 개체지향 수업 들으면서 클래스간의 결합도와 의존성에 관해 알게되면서 그게 이거였구나~ 싶었던 기억이 난다.

```java
public class Foo {
    private int a;
    private int b;

    public Foo(int a, int b) {
        this.a = a;
        this.b = b;
    }
}

public class Bar {
    private Foo foo;

    public Bar(int a, int b) {
        foo = new Foo(a,b);
    }
}
```

의존성이 높은 코드. Foo의 생성자가 수정된다면 Bar는 바로 컴파일 에러가 나버린다.

```java
// 결합도를 낮춘 코드
public class Bar {
    private Foo foo;

    public Bar(Foo foo) {
        this.foo = foo;
    }
}
```

이렇게 `foo` 개체를 생성자의 인자로 해주면 `Foo` 의 생성자가 바뀜에 따라 `Bar`를 건드릴게 적어진다 (결합도가 줄어든다 == 의존성이 낮아진다).

Spring 에서도 비슷한게 있다.

```java
// 📃 StudentService.java
public class StudentService {
    ...

    public Stduent getStudent(){...}
}

// 📃 StudentController.java
public class StudentController {
    private StudentService studentService;

    public StudentController() {
        stdentService = new StudentService();
    }

    @GetMapping(...)
    public Student getStudent() {
        return studentService().getStudent();
    }
}
```

의존성이 높은 코드이다. 의존성을 줄여보자

```java
// 📃 StudentService.java
@Service
public class StudentService {
    ...

    public Stduent getStudent(){...}
}

// 📃 StudentController.java
public class StudentController {
    private StudentService studentService;

    @Autowired
    public StudentController(StudentService studentService) {
        this.stdentService = stdentService;
    }

    @GetMapping(...)
    public Student getStudent() {
        return studentService().getStudent();
    }
}
```

이렇게 개체를 생성자에 넣어줌으로써 의존성을 줄였다.  
보면 `@Service` `@Autowired`같은 어노테이션이 붙었는데 이것들은 IOC와 Bean과 관련되어있다.

스프링은 누가 main 함수에다가 코드 작성해서 개체 생성해주고 이런게 아니다보니까 InversionOfControl 이라고 해서 제어의 역전을 통해 사용자가 아니라 컴퓨터가 직접 코딩을 한다. 이 때 컴퓨터가 관리하는 개체들을 Bean이라고 하는데 위의 예제에서는 `StudentService` 개체가 그 Bean이 되겠다.  
그래서 저렇게 어노테이션을 넣어주면 컴퓨터가 `StudentService` 개체를 생성해서 `StudentController` 클래스의 생성자에 넣어준다고 한다.
