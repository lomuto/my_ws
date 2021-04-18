#include <bits/stdc++.h>

using namespace std;

int arr[50001];

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    // for(int i=0; i<people.size(); i++)
    //     cout << people[i] << ' ';
    // cout << '\n';

    int SIZE = people.size();
    int cnt = SIZE;
    for (int st = 0, end = SIZE - 1; st < end; end--) {
        if (people[st] + people[end] <= limit) {
            cnt -= 1;
            st++;
        }
    }

    return cnt;
}