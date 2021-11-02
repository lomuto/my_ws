# 문자열 ~ 정수

자꾸 까먹고 문제풀때 구글링 해야해서 적어놓는다...

### 문자열 -> 정수

```java
String str = "12345";
Integer.parseInt(str);  // 12345
```

### 정수 -> 문자열

```java
int num = 99865;
Integer.toString(num) // "99865"
```

### 문자열 -> char 배열

```java
String str = "12345";
str.toCharArray();  // 12345
```

### 정수 -> char 배열

```java
int num = 9923812;
String str = Integer.toString(num);
str.toCharArray();
```
