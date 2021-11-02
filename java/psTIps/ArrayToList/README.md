# 배열을 list로

배열을 list로 바꾸기 이전에 그 반대를 잠깐 보자.

```java
String[] stringArray = new String[size];

...

List<Stirng> stringList = Arrays.asList(stringArray);
```

간단하다.

그럼 list를 배열로 바꿔보자.

```java
ArrayList<String> stringList = new ArrayList<>();

...

String[] stringArray = stringList.toArray(new String[stringList.size()]);
```

근데 여기서 중요한건.. `String` 과 같은 개체타입은 상관없는데 `Integer`와 `int` 같은 개체형, 값형(preemiptive type) 끼리는 상호교환이 안된다. 특히나 **list -> 배열** 에서

```java
ArrayList<Integer> intList = new ArrayList<>();

...

int[] intArray = intList.toArray(new int[intList.size()]);  // type Integer cannot be casted to int error
```

이런경우는 배열 만들어서 반복문 돌려야한다 그냥 ㅎㅎ
