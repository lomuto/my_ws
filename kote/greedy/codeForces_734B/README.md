# 효율적인 방법의 제고

[https://codeforces.com/problemset/problem/734/B](https://codeforces.com/problemset/problem/734/B)

## 내 코드

```cpp
#include <bits/stdc++.h>
using namespace std;

int digits[7];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> digits[2];
    cin >> digits[3];
    cin >> digits[5];
    cin >> digits[6];

    unsigned long long ans = 0;

    while (digits[2] && digits[5] && digits[6]) {
        digits[2]--;
        digits[5]--;
        digits[6]--;
        ans += 256;
    }

    while (digits[3] && digits[2]) {
        digits[3]--;
        digits[2]--;
        ans += 32;
    }
    cout << ans;
}
```

시간복잡도는 선형시간이다.  
PS는 `메모리 < 속도` 라지만 버리는 메모리가 없지않아 있다.

두마리 토끼를 잡아보자.

## Better

```cpp
int TWO, THREE, FIVE, SIX;

    cin >> TWO;
    cin >> THREE;
    cin >> FIVE;
    cin >> SIX;

    long long sum = 0;
    int CNT_256 = min(TWO, min(FIVE, SIX));
    sum += CNT_256 * 256;

    TWO -= CNT_256;

    int CNT_32 = min(TWO, THREE);
    sum += CNT_32 * 32;

    cout << sum;
```

min 함수를 활용해 시간복잡도를 상수시간으로 끌어내렸다.

내가 고민했던게 사용된 숫자의 카운팅이었는데,  
중복되는 `2` 의 경우 256을 구한 만큼을 빼주고 32를 계산하면 된다.
