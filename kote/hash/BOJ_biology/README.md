# 해시맵 정렬

[https://www.acmicpc.net/problem/4358](https://www.acmicpc.net/problem/4358)

### 들어오는 문자열에 대해 중복유무를 검사하는 문제.

1. map에 해당 문자열을 key값으로 default 1값을 value로 `insert`
2. 동일한 동작에 대해 중복된 항목일 경우 `pair<map::iterator,bool>`에 second에 false를 리턴하므로, 해당 경우 value값을 1 증가.
3. **Cpp의 map은 key값을 토대로 정렬을 수행하는 balanced tree이므로** 문자열의 오름차순으로 출력해야하므로 iterator로 그대로 출력하면 됨

만약에 문제가 key가 아닌 value로 정렬해야하는 문제라고 해보자.

```cpp
map<string,int> mp;
...
vector<pair<string,int>> v(mp.begin(),mp,end());
```

로 다음과 같이 map의 요소들을 vector로 옮겨서 vector에 대한 sort를 진행하면 된다.
