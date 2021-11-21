# @Transient

Transient: 일시적인, 잠시 체류하는 ~~ **Temporary**

Temporary 와 비슷한 뜻을 가진 Transient 라는 단어.  
이 Annotation의 기능을 알아보자...

### 엔티티에 관한 내용만 다뤘다. 실제로 Transient 어노테이션은 테이블에서 해당 데이터를 컬럼에서 제외시키는게 아니라 영속 대상에서 제외시키는 어노테이션이다. (메소드에도 적용 가능) 이 내용은 다음 링크에 자세히...

[https://gmoon92.github.io/jpa/2019/09/29/what-is-the-transient-annotation-used-for-in-jpa.html](https://gmoon92.github.io/jpa/2019/09/29/what-is-the-transient-annotation-used-for-in-jpa.html)

```java
@Table
@Entity
public class Student {
     @Id
    @SequenceGenerator(
            name = "student_sequence_generator",
            sequenceName = "student_sequence",
            /*initialValue = default 1*/
            allocationSize = 1
    )
    @GeneratedValue(
            strategy = GenerationType.SEQUENCE,
            generator = "student_sequence_generator"
    )

    private Long id;
    private String name;
    private String email;
    private LocalDate dob;
    private int age;
}
```

ORM에 쓰이는 다음과 같은 테이블이 있다고 해보자.

**Date of Birth가 있는데 나이를 굳이 따로 db에 저장해 줄 필요가 있을까?**

나이는 생년월일을 통해 유추가 가능하다. **API 엔드포인트에서 개체 리턴 시 getter를 통해 json 파일을 response 해주는것에 착안해 age는 따로 저장하지 않고 getter를 통해 관리해보자.**

```java
@Table
@Entity
public class Student {
    ...
    @Transient
    private int age;

    ...

    public int getAge() {
        return Period.between(this.dob, Local.now()).getYears();
    }
}
```

위와 같은 설정을 통해 데이터베이스에는 나이를 저장하지 않으면서도, response 시 나이 정보를 전송해줄 수 있다
