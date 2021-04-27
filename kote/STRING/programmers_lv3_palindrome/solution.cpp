#include <bits/stdc++.h>

using namespace std;

string str;

bool is_palindrome(int st, int end) {
    while (st < end) {
        if (str[st++] != str[end--])
            return 0;
    }
    return 1;
}

int solution(string s) {
    str = s;
    int answer = 0;
    int LEN = s.size();
    int MAX = 0;
    for (int len = LEN - 1; len; len--) {
        for (int st = 0, end = st + len; end < LEN; st++, end++) {
            // cout << "st: " << st <<" end: " << end << '\n';
            if (is_palindrome(st, end))
                return end - st + 1;
        }
    }
    return 1; // for문 다 돌아도 없으면 팰린드롬 없는 문자열 == 최대 펠린드롬의 길이는 1
}