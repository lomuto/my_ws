# 나이순 정렬

[https://www.acmicpc.net/problem/10814](https://www.acmicpc.net/problem/10814)

---

```
회원들을 나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오.
```

1. `pair<pair<int,string>,int>`

```cpp
bool cmp(pair<pair<int, string>, int> *a, pair<pair<int, string>, int> *b) {
    if ((a->first).first == (b->first).first) {
        return a->second < b->second;
    } else {
        return (a->first).first < (b->first).first;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<pair<int, string>, int> *> v;

    int age;
    string name;
    for (int i = 0; i < n; i++) {
        cin >> age >> name;
        pair<int, string> temP = make_pair(age, name);
        v.push_back(new pair<pair<int, string>, int>{temP, i});
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
        cout << (v[i]->first).first << ' ' << (v[i]->first).second << '\n';
}
```

보기만 해도 머리가 아프다

```cpp
pair<pair<int,string>,int>
```

를 풀어서 설명하자면 `pair<pair<나이,이름>,인덱스>`이다.  
원래같으면 `pair<int,age>` 로 이름과 나이만 받았겠지만 나이가 같을경우 먼저 가입한 (인덱스) 순으로 오름차순 정렬 하랬으니 index를 또 입력받는다.

`vector` 의 type은 `pair<pair<int,string>,int>` 의 **포인터** 로 주었다. 그래야 빠르니까...  
pair 안의 pair는 포인터변수가 아니므로 `(v[i]->first).first` 이렇게 접근해야 한다.

아예 pair 안의 pair 도 `pair<pair<int,string>*,int>*` 같이 포인터로 줘서 `v[i]->first->first` 같이 조금 더 직관적인 연산자로 접근할 수 있게 줘봤는데 메모리도 더 잡아먹고 속도도 더 느렸다. 포인터로 줬는데 왜 더 느릴까..? [http://boj.kr/7d071db3ba434c2fa4080c01401d9145](http://boj.kr/7d071db3ba434c2fa4080c01401d9145)

---

2. stable_sort  
   [https://www.acmicpc.net/source/27697856](https://www.acmicpc.net/source/27697856)

이 글을 쓴 이유다.  
일반 `sort` 대신 `stable_sort` 를 사용하면 `compare` 함수의 조건이 아닐 경우에는 순서를 변경하지 않는다.

```cpp
bool cmp(pair<int, string> *a, pair<int, string> *b) {
    if (a->first == b->first) {
        return false;
    } else {
        return a->first < b->first;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, string> *> v;

    int age;
    string name;
    for (int i = 0; i < n; i++) {
        cin >> age >> name;
        v.push_back(new pair<int, string>{age, name});
    }

    stable_sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
        cout << (v[i])->first << ' ' << v[i]->second << '\n';
}
```

훨씬 깔끔하고 좋다  
하지만 만약에 `나이가 같으면 먼저 가입한 사람이 뒤에오는 순서로` 같은 조건이 있으면 위의 방법으로 인덱스 내림차순 정렬 해야한다.
