#include <bits/stdc++.h>

using namespace std;

vector<string> parseWithDelimiter(const string &src, char delimiter) {
    vector<string> ret;
    int stPos = 0;
    int endPos = 0;

    while (true) {
        stPos = src.find_first_not_of(delimiter, stPos);
        if (stPos == string::npos) {
            break;
        }

        endPos = src.find_first_of(delimiter, stPos);
        ret.push_back(src.substr(stPos, endPos - stPos));

        if (endPos == string::npos) {
            break;
        }

        stPos = endPos + 1;
    }

    return ret;
}

int main() {
    string str = "970029019201001402932103";
    vector<string> ret = parseWithDelimiter(str, '0');

    for (string s : ret) {
        cout << s << '\n';
    }
}