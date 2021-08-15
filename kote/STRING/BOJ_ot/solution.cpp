#include <bits/stdc++.h>

using namespace std;

int getMinByStr(const string &time) {
    int hour = atoi(time.substr(0, 2).c_str());
    int minute = atoi(time.substr(3, 2).c_str());
    return minute + hour * 60;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string startStr;
    string endConfStr;
    string endStreamStr;
    vector<string> chatLog;
    unordered_set<string> isJoined;
    unordered_set<string> isAttended;

    cin >> startStr >> endConfStr >> endStreamStr;

    int startTime = getMinByStr(startStr);
    int endConfTime = getMinByStr(endConfStr);
    int endStreamTime = getMinByStr(endStreamStr);

    // cout << "start, endConf, endStream: " << startTime << ' ' << endConfTime << ' ' << endStreamTime << '\n';

    string buffer;
    while (!cin.fail()) {
        getline(cin, buffer);
        chatLog.push_back(buffer);
    }

    int cnt = 0;
    for (const string &s : chatLog) {
        if (s.size() == 0) {
            continue;
        }
        int logTime = getMinByStr(s);
        if (logTime > endStreamTime) {
            break;
        }
        string person = s.substr(6);
        // cout << "logTime: " << logTime << '\n';
        // cout << "NAme: " << s.substr(6) << '\n';
        if (logTime <= startTime) { // 참여
            isJoined.insert(person);
        }
        if (logTime >= endConfTime && logTime <= endStreamTime) {
            if (isJoined.find(person) != isJoined.end()) {
                isAttended.insert(person);
            }
        }
    }

    cout << isAttended.size() << '\n';
}