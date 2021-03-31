# Prefix Sum

[https://codeforces.com/problemset/problem/466/C](https://codeforces.com/problemset/problem/466/C)

<br/>

### **자료형 확인**

입력값의 개수는 최대 `5*10^5`이고 각각의 원소의 절댓값은 `a[i]<=10^9` 이다.  
Prefix sum을 저장할 배열 `v` 의 원소의 최댓값은 고로 `5*10^14`이다.  
signed int 가 표현할 수 있는 최댓값이 `2^32`은 `2^32 > 2^30~~10^9` 이므로 int로 변수 설정 시 overflow가 일어난다.  
자로형 체크 잘 하자.

<br/>

---

<br/>   
   
### **Time complexity**   
   
- 1트: 다항시간
```cpp
for (int st = 1; st <= n - 2; st++) {
        for (int end = st + 1; end <= n - 1; end++) {
            if (prefix(1, st) == prefix(st + 1, end) && prefix(st + 1, end) == prefix(end + 1, n))
                cnt++;
        }
    }
```   
   
부분합이 같게 prefix sum 전체를 3등분 하는 경우의 수를 찾아야 하므로 두개의 pivot st,end를 두어 `1~st`, `st+1~end`, `end+1~n` 의 부분합이 같은지 배열 전체를 순회하며 확인한다.   
시간복잡도는 어림잡아도 `n^2`인 다항시간.   
**효율적이지 않다.**   
   
---

- 2트: Floating point exception

```cpp
for (int i = 1; i < n + 1; i++) {
        if (v[i] * 3 == end) { // floating point exception when v[i] is 0 `!(end % v[i])`
            for (int j = i + 1; j < n; j++) {
                if (v[j] == 2 * v[i])
                    cnt++;
            }
        }
    }
```

prefix 전체를 3등분 해야 한다는 아이디어에서 착안해, 시작 pivot과 `v[n]` 이 3으로 나누어 떨어져야 한다는 점 활용.  
`!(end % v[i])` 로 조건문을 줬을 때는 **v[i] 가 0 일 경우에 floating point exception 발생**하는점 간과.  
시간복잡도도 다항시간.

---

- 3트: 성공

```cpp
#include <bits/stdc++.h>
#include <cctype>
using namespace std;
vector<long long> v;

int prefix(int st, int end) {
    return v[end] - v[st - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n < 3) {
        cout << 0;
        return 0;
    }

    v.resize(n + 1);
    v.push_back(0);

    for (int i = 1, sum = 0; i < n + 1; i++) {
        cin >> v[i];
        v[i] = v[i] + v[i - 1];
    }

    long long end = v[n];

    if (end % 3) {
        cout << 0;
        return 0;
    }

    long long cnt = 0;
    long long cnt3 = 0;
    long long starting_number = end / 3;
    if (v[1] == starting_number)
        cnt3++;
    for (int i = 2; i < n; i++) {
        if (v[i] == starting_number * 2)
            cnt += cnt3;
        if (v[i] == starting_number)
            cnt3++;
    }

    // for (int i = 1; i < n + 1; i++) {
    //     if (v[i] * 3 == end) { // floating point exception when v[i] is 0 `!(end % v[i])`
    //         for (int j = i + 1; j < n; j++) {
    //             if (v[j] == 2 * v[i])
    //                 cnt++;
    //         }
    //     }
    // }

    // for (int st = 1; st <= n - 2; st++) {
    //     for (int end = st + 1; end <= n - 1; end++) {
    //         if (prefix(1, st) == prefix(st + 1, end) && prefix(st + 1, end) == prefix(end + 1, n))
    //             cnt++;
    //     }
    // }
    cout << cnt;
}
```

prefix sum의 배열이 `[0 3 3 6 7 8 6 6 9]` 라고 해보자.  
`3`,`6`,`9` 를 기점으로 배열을 3등분 할 수 있다.  
고로 3과 6을 짝지어 뽑는 경우의 수 `2*3=6` 을 경우의 수라 할 수 있다. 이 경우 1회 순회를 통해 선형시간내에 `v[i] == v[n]/3` 인 원소의 수와 `v[i] == (v[n]/3)*2` 인 원소의 수의 곱을 통해 답을 구할 수 있다

하지만 `[0 3 `**6**` 3 7 8 6 6 9]` 과 같이 **3이 항상 6 뒤에 있는게 아니라 순서가 섞여있다면** 단순 3과6의 개수의 곱이 전체 경우의 수에 부합하지 않는다.

이를 해결하기 위해 두개의 count변수 `cnt`,`cnt3`을 두어 `v[i] == v[n]/3` 인 i의 개수를 `cnt3`에 세다가 `v[i] == (v[n]/3)*2` 를 만나면 이전까지의 `cnt3`을 `cnt` 에 더해가는 방식으로 해결했다.
