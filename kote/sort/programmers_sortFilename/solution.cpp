#include <bits/stdc++.h>
#include <cctype>

using namespace std;

pair<string, pair<string, int>> FILES[1001];

bool cmp(pair<string, pair<string, int>> a, pair<string, pair<string, int>> b) {
    int temp = strcasecmp(a.second.first.c_str(), b.second.first.c_str());
    if (!temp) {
        return a.second.second < b.second.second;
    } else {
        return temp > 0 ? false : true;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    answer.resize(files.size());

    string buf;
    for (int i = 0; i < files.size(); i++) {
        string HEAD, NUM;
        buf = files[i];
        int flag = 0;
        for (int i = 0; i < buf.size(); i++) { // head 랑 num 사이에 공백이오나?
            if (isdigit(buf[i])) {
                flag = 1;
                NUM += buf[i];
            } else if (!flag) {
                HEAD += buf[i];
            } else
                break;
        }
        FILES[i] = make_pair(buf, make_pair(HEAD, atoi(NUM.c_str())));
    }

    // cout << '\n';
    // for(int i=0; i<files.size(); i++){
    //     cout << FILES[i].first << ' ';
    //      cout   << FILES[i].second.first << ' ';
    //      cout   << FILES[i].second.second << '\n';
    // }

    stable_sort(FILES, FILES + files.size(), cmp);

    for (int i = 0; i < files.size(); i++) {
        answer[i] = FILES[i].first;
    }

    return answer;
}