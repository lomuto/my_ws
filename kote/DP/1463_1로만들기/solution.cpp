#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<int> mem;
    mem.reserve(1000001);

    mem[1] = 0;
    mem[2] = 1;
    mem[3] = 1;
    mem[4] = 2;

    int N;
    cin >> N;

    for (int i = 5; i <= N; i++) {
        if (!(i % 2) && !(i % 3)) // i%6
            mem[i] = 1 + min(mem[i - 1], min(mem[i / 3], mem[i / 2]));
        else if (!(i % 3))
            mem[i] = 1 + min(mem[i - 1], mem[i / 3]);
        else if (!(i % 2))
            mem[i] = 1 + min(mem[i - 1], mem[i / 2]);
        else
            mem[i] = 1 + mem[i - 1];
    }

    cout << mem[N];
}