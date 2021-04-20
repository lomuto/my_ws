#include <bits/stdc++.h>
using namespace std;

int palindrome(const string &s) {
    int SIZE = s.size();
    pair<int, int> p{0, SIZE - 1};
    int init_p_sec = p.second;
    for (int i = 0; i < SIZE; i++) {
        p.second = init_p_sec - i;
        for (int j = 0; p.second + j < SIZE; j++) {
            int flag = 1;
            int left = p.first + j;
            int right = p.second + j;
            while (left < right) {
                if (s[left] == s[right]) {
                    left++;
                    right--;
                } else {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                return p.second - p.first + 1;
        }
    }
}

int solution(string s) {
    int answer = palindrome(s);

    return answer;
}