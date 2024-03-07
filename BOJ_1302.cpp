#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int N;
    string str;
    map<string, int> m;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> str;
        if(m.find(str) != m.end()) {
            m.find(str)->second++;
        } else {
            m.insert({str, 1});
        }
    }

    int value = m.begin()->second;
    string answer = m.begin()->first;

    for(auto iter = m.begin(); iter != m.end(); ++iter) {
        if(iter->second > value) {
            value = iter->second;
            answer = iter->first;
        }
    }
    cout << answer;
}