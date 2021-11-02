# 해시맵 순회

C++은 해시맵 순회가 참 쉽다...

```cpp
unordered_map<int,int> map;
...
for(const auto& it : map) {
    map.first; // key
    map.value; // value
}
```

java의 해시맵 순회도 알아보자.  
예시로 사용할 해시맵은

```java
HashMap<String, Integer> hmap = new HashMap()<>;
```

이다.

1. keySet()

```java
for(String key : hmap.keySet()) {
    hmap.get(key); // returns value of key
}
```

2. entrySet()

```java
for(Map.Entry<String, Integer> entry : hmap.entrySet()) {
    entry.getKey();     // key
    entry.getValue();   // value
}
```

편한거 갖다가 쓰면 된다.
