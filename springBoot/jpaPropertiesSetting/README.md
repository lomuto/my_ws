# application.properties 설정

```java
spring.datasource.driver-class-name=com.mysql.cj.jdbc.Driver
spring.datasource.url= /*url:port/table*/
spring.datasource.username= /*username*/
spring.datasource.password= /*password*/
spring.jpa.show-sql=true    // displaies sql
spring.jpa.hibernate.ddl-auto=create-drop   // 테스트 시 설정. 매 프로그램 시작마다 테이블 초기화됨
```
