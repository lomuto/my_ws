#include <bits/stdc++.h>
#include <cctype>

using namespace std;

vector<pair<string, string>> LOG;
map<string, string> INFO;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    for (int i = 0; i < record.size(); i++) {
        string cur_record = record[i];
        if (cur_record[0] == 'E') { //ENTER
            string uid = "";
            string nickname = "";
            int p;
            for (p = 6; cur_record[p] != ' '; p++) {
                uid += cur_record[p];
            }
            for (p++; p < cur_record.size(); p++)
                nickname += cur_record[p];
            LOG.push_back(make_pair("ENTER", uid));
            INFO[uid] = nickname;
        } else if (cur_record[0] == 'L') { //LEAVE
            string uid = "";
            for (int p = 6; p < cur_record.size(); p++) { // LEAVE command ends with uid
                uid += cur_record[p];
            }
            LOG.push_back(make_pair("LEAVE", uid));
        } else { // CHANGE
            string uid = "";
            string nickname = "";
            int p;
            for (p = 7; cur_record[p] != ' '; p++) {
                uid += cur_record[p];
            }
            for (p++; p < cur_record.size(); p++)
                nickname += cur_record[p];
            INFO[uid] = nickname;
        }
    }

    // cout << "DEBUG [LOG]\n";
    // for(int i=0; i<LOG.size(); i++){
    //     cout << LOG[i].first << '\n';
    //     cout << LOG[i].second << '\n';
    // }

    for (int i = 0; i < LOG.size(); i++) {
        string buf;
        if (LOG[i].first == "ENTER") {
            buf = INFO[LOG[i].second] + "님이 들어왔습니다.";
            answer.push_back(buf);
        } else {
            buf = INFO[LOG[i].second] + "님이 나갔습니다.";
            answer.push_back(buf);
        }
    }

    return answer;
}