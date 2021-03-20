#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(string a, string b) {
    if (a[0] == b[0]) {
        return a + b > b + a;
    } else
        return a[0] > b[0];
}

int main() {
    int n;
    cin >> n;

    string *arr = new string[n];

    int zero_cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (!(arr[i][0] - '0'))
            zero_cnt++;
    }

    if (zero_cnt == n) {
        cout << 0;
        return 0;
    }

    sort(arr, arr + n, cmp);

    string ans = "";
    for (int i = 0; i < n; i++)
        ans += arr[i];

    cout << ans;

    delete[] arr;
}