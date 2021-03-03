#include <cctype>
#include <string>
// 벡터쓸줄 모르지만 문제에 기본으로 주길래... 나중에 이거써서 풀어보기
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    for (int i = 0, w = 0; i < s.size(); i++, w++) {
        if (s[i] == ' ')
            w = -1;

        if (w % 2 == 0) {
            answer += toupper(s[i]);
        } else {
            answer += tolower(s[i]);
        }
    }

    return answer;
}