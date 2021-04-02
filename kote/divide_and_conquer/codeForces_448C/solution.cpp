#include <bits/stdc++.h>
using namespace std;

int f[5001];
int n;

int DC(int st, int end) {
    if (end == st) {
        if (f[st]) {
            f[st] = 0;
            return 1;
        } else
            return 0;
    } else if (end < st)
        return 0;

    // cout << "CUrrent st ~ end: " << st << " ~ " << end << "\n\n";

    int shortest = 1000000009;
    for (int i = st; i <= end; i++) {
        shortest = min(shortest, f[i]);
    }
    // if (shortest >= end - st + 1) {
    //     return (end - st + 1);
    // }
    int cnt = 0;
    for (int i = st; i <= end; i++)
        f[i] -= shortest;
    cnt += shortest;

    int pivot_st = st;
    int pivot_end;
    int i, j;
    for (i = st; i <= end; i++) {
        if (f[i] != 0) {
            for (j = i + 1; j <= end; j++) {
                if (f[j] == 0)
                    break;
            }
            cnt += DC(i, j - 1);
            i = j;
        }
    }
    return min(cnt, end - st + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> f[i];

    int ans = DC(1, n);

    cout << ans;
}