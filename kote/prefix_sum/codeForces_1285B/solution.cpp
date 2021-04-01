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