#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
    string as = to_string(a);
    string bs = to_string(b);
    return stoi(as + bs) > stoi(bs + as);
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    int flag = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (!numbers[i])
            flag++;
        answer += to_string(numbers[i]);
    }
    if (flag == numbers.size())
        return "0";
    else
        return answer;
}