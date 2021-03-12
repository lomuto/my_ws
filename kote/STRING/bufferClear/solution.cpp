#include <cctype>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int N;
    cin >> N;

    string temp;

    cin.ignore(__INT_MAX__, '\n'); // MUST CLEAR BUFFER
    cin.clear();

    for (int i = 0; i < N; i++) {
        getline(cin, temp, '\n');

        temp[0] = toupper(temp[0]);

        cout << temp << '\n';
    }
}