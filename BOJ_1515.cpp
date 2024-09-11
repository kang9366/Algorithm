#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    string str;
    cin >> str;

    queue<char> q;
    for(int i = 0; i < str.size(); i++) q.push(str[i]);
    
    int answer = 0;
    while(!q.empty()) {
        str = to_string(++answer);
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == q.front()) q.pop();
            if(q.empty()) break;
        }
    }
    cout << answer;
}