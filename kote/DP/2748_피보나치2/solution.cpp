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