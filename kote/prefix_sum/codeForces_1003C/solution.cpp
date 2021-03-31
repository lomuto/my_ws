#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int ps[n + 1];
    ps[0] = 0;
    float ans = 0;

    for (int i = 1, buf; i < n + 1; i++) {
        cin >> buf;
        ps[i] = buf + ps[i - 1];
    }

    for (int size = k; size < n + 1; size++) {
        for (int st = 1; st + size < n + 2; st++) {
            ans = max(ans, (float)(ps[st + size - 1] - ps[st - 1]) / size);
        }
    }
    cout << fixed;
    cout.precision(7);
    cout << ans;
}