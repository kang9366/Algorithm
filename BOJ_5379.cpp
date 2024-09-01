#include <iostream>
#include <stack>
#include <list>

#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;

    string str;
    while(T--) {
        cin >> str;
        list<char> answer;
        auto cursor = answer.begin();
        for(auto &s : str) {
            if(s == '-' && cursor != answer.begin()) cursor = answer.erase(--cursor);
            else if(s == '<' && cursor != answer.begin()) cursor--;
            else if(s == '>' && cursor != answer.end()) cursor++;
            else if(s != '>' && s != '<' && s != '-') answer.insert(cursor, s);
        }
        for(auto &i : answer) cout << i;
        cout << endl;
    }
}