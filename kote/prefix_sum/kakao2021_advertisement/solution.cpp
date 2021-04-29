#include <bits/stdc++.h>

using namespace std;

int get_sec(string time) {
    int h, m, s;
    h = atoi(time.substr(0, 2).c_str());
    m = atoi(time.substr(3, 2).c_str());
    s = atoi(time.substr(6, 2).c_str());
    return h * 3600 + m * 60 + s;
}

string format(int a) {
    if (a == 0)
        return "00";
    else if (a / 10 == 0)
        return '0' + to_string(a);
    else
        return to_string(a);
}

void get_time(string &time, int s) {
    string hour = format(s / 3600);
    s = s % 3600;
    string min = format(s / 60);
    s = s % 60;
    string sec = format(s);
    time = hour + ':' + min + ':' + sec;
}

int *TIME;

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    int TOTAL_TIME = get_sec(play_time);
    TIME = new int[TOTAL_TIME + 1];
    // cout << "DEBUG: TIME\n";
    // cout << TOTAL_TIME << '\n';

    // cout << "DEVUG: get_time test\n";
    // string temp;
    // get_time(temp,TOTAL_TIME);
    // cout << temp << '\n';

    // cout << "DEBUG: st,end\n
    int log_SIZE = logs.size();
    for (int i = 0; i < log_SIZE; i++) {
        string buf = logs[i];
        int st = get_sec(buf.substr(0, 8));
        int end = get_sec(buf.substr(9, 8));
        // cout << "st: " << st << " end: " << end << '\n';
        for (int i = st; i <= end; i++)
            TIME[i]++;
    }

    int adv_len = get_sec(adv_time);
    // cout << "DEBUG: adv_len: " << adv_len << '\n';

    int MAX = 0;
    string ans;
    int index = 0;
    for (int i = 0; i <= TOTAL_TIME - adv_len; i++) {
        int sum = 0;
        for (int p = i; p <= i + adv_len; p++) {
            sum += TIME[p];
        }
        if (MAX < sum) {
            index = i;
            MAX = sum;
        }
    }
    get_time(ans, index);
    return ans;
}