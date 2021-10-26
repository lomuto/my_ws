cpp에서 unordered_map의 반복하기

```cpp
unordered_map<...,...> map;
...
for(const auto& it : map) {
    it.first // key
    it.second // value
}
```

문자가 알파벳으로 한정이니까 크기가 26인 배열 만들어놓고  
`arr[c-'0']` 이런식으로 원소 접근해서 26짜리 배열 돌면서 min인거 sum에 더해주는거도 하나의 방법
