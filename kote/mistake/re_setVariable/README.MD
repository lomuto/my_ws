# Re-set global variable

[https://algospot.com/judge/problem/read/FESTIVAL#](https://algospot.com/judge/problem/read/FESTIVAL#)

### What have I done wrong?

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int c, n, l;
    vector<int> v;

    cin >> c;

    cout << fixed;
    cout.precision(11);

    double MIN = 100;
    for (int i = 0; i < c; i++) {
        cin >> n >> l;
        v.resize(n);

        for (int t = 0; t < n; t++)
            cin >> v[t];

        for (int st = 0; st <= n - l; st++) {
            for (int end = st + l - 1; end < n; end++) {
                int temp = 0;
                for (int pivot = st; pivot <= end; pivot++)
                    temp += v[pivot];
                MIN = min(MIN, (double)temp / (end - st + 1));
            }
        }
        cout << MIN << '\n';
    }
}
```

Whole case will be repeated `c` times.

But forgot to re-set the `MIN`

Move declaration of `MIN` inside outter for loop or add `MIN = 0` at the end of loop
