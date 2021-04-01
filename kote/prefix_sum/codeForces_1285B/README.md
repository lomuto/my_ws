# Maxium segment of all prefix-sum

[https://codeforces.com/problemset/problem/1285/B](https://codeforces.com/problemset/problem/1285/B)

- ### 자료형 체크
  `|a| < 10^9` 이지만

```
It is guaranteed that the sum of n over all test cases doesn't exceed 10^5
```

라는 조건에 낚여서 int로 변수type 줬음.

p[n] 이 10^5 이 안넘는다는거지 중간에는 넘었다가 내려올 수 있음...  
`long long p[]` 로 했어야함.

---

- ### 전역변수 활용

임베디드 만지작 거릴때 버릇이 남아서 그런지  
자꾸 메모리 아끼려고 지금 문제같이 여러번의 TC가 주어질 때 그때마다 배열 크기 입력받아서

```cpp
cin >> n;
long long* p = new long long[n];
```

으로 동적할당 받는 쓸데없는 짓 했었음.

학교 과제하는거 아니고, 문제조건의 최대 메모리도 256mb = 256,000kb = 256,000,000byte 로 차고 넘치니까

```cpp
long long p[100001];

int main(){
    ...
}
```

로 전역변수로 최대크기+1 잡아주고 문제 풀자.

---

- ### 단항연산자 금지

0또는 1만 들어가는 `flag`를 두어서 조건문으로 변수 검사할 때, 0 일 때 조건 검사를 `if(!flag)` 이렇게 했었는데 겉멋인거같음.  
`if(flag==0)` 그냥 이렇게 하는게 가독성도 좋고 깔끔하다...

`flag` 의 상태 변화 시 `flag++` 또는 `flag--` 많이 했었는데 파이썬에서 단항연산자 왜 없앴는지 알꺼같다.  
문제에서 조건문 2번 검사할때가 있어서 `flag--` 했을 때 `1->0->-1` 이렇게 `0`일때도 `flag--`해버려서 `if(flag)` 에서 flag가 `-1`값이 됨에따라 의도치않게 통과되는 코드를 만들었다.  
그냥 깔끔하게

```cpp
flag = 0;
```

으로 explicitly 하게 변수에 값 할당해주자.

---

- ### 구간합의 최대

```cpp
int arr[] = {0,-2,7,-9,6,2,6,-1,-15,9,15};
```

가 있을 때

```cpp
int p[] = {0,-2,5,-4,2,4,10,9,-6,3,18}
```

와 같이 첫번째 인덱스를 0 을 준 `p[i] = p[i-1]+arr[i] (i>0)` 을 만족하는 구간합의 배열 `p` 가 존재한다.

여기서 임의의 segment의 합이 최대가 되는 경우는?  
**`p의 최대값 - p의 최소값` (이 때 최소값은 최대값보다 뒤에 있어야함)**

무식하게 이중 for문 돌 필요 없이 p의 원소의 최대 최소 찾아서 뺀게 임의의 segment의 구간합 최대이다.

---

- ### m2[0] = 1000000000?

문제 조건이 segment의 합이 전체합이 되면 안된다는 조건이 있었다.  
`p의 최대값 - p의 최소값` 이 segment의 합의 최대일 때, **최소값은 최대값보다 뒤에 있어야 한다**는 조건 때문에, 인덱스에 따라 그 당시의 `p` 의 최소값을 저장할 구간합최소배열 `m` 에 값을 저장한다. 이 때 index 0은 p와 같이 0값으로 둔다.

**이 때 p의 상태는 크게 두가지로 나뉜다.**

1. p 의 최소가 음수
2. p 의 최소가 양수

- [1] 의 경우에는 `m[0]`이 0이어도 중간의 음수값으로 인해 최소값이 정상적으로 설정되어 문제조건 (segment != total) 에 부합하는 정상적인 결과가 나온다. **하지만 p[1]이 음수이면서 최소일 경우** `segment 의 최대합 = 전체의 최대합`이 되어버리므로, `p[n]` 까지 탐색하지 않아야 한다.
- [1] 의 한계점과 [2]의 문제를 같이 보자,  
  `m[0] = 1000000000` 을 하면 모든 문제가 해결될 것 같지만, segment[1,1]은 정상적인 값이 아닌 엉뚱한값이 나온다 ( p[1]-m[0] ).  
  고로 배열 `m2`를 따로 만들어 `m2[0] = 1000000000` 을 통해 정상적인 양수이며 최소인 값을 구하고, [1] 에서 비교하지 못했던 `p[n]` 단 한번의 비교를 할 때 쓰면 된다.

---

```cpp
#include <bits/stdc++.h>
using namespace std;

long long ps[100001];
long long m2[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int TC, n;

    cin >> TC;

    for (int c = 0; c < TC; c++) {
        cin >> n;

        ps[0] = 0;
        m[0] = 0;
        m2[0] = 1000000000;

        for (int i = 1, buf; i < n + 1; i++) {
            cin >> buf;
            ps[i] = buf + ps[i - 1];
        }
        for (int i = 1; i < n + 1; i++) {
            m[i] = min(m[i - 1], ps[i]);
        }
        for (int i = 1; i < n + 1; i++) {
            m2[i] = min(m2[i - 1], ps[i]);
        }
        long long Yasser = ps[n];
        int flag = 1;
        for (int i = 1; i < n; i++) {
            if (ps[i] - m[i - 1] >= Yasser) {
                flag = 0;
                break;
            }
        }
        if (ps[n] - m2[n - 1] >= Yasser) {
            flag = 0;
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
```
