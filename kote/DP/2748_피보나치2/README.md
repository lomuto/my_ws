# Fibonacci

[https://www.acmicpc.net/problem/2748](https://www.acmicpc.net/problem/2748)

**In most case, DP must be held with array instead recursion**

<br/>

```cpp
// Timeout
#include <iostream>

using namespace std;

int FIB(int n) {
    if (!n)
        return 0;
    if (n == 1)
        return 1;

    return FIB(n - 1) + FIB(n - 2);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    cout << FIB(N);
}
```

```cpp
// Answer
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long mem[91];
    mem[0] = 0;
    mem[1] = 1;

    int N;
    cin >> N;

    for (int i = 2; i <= N; i++)
        mem[i] = mem[i - 1] + mem[i - 2];
    cout << mem[N];
}
```
