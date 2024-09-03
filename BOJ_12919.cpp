#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S, T;

bool flag = false;

void dfs(string str) {
    if(flag) return;
    if(str.size() == S.size()) {
        if(str == S) flag = true;
        return;
    }

    if(str[0] == 'B') {
        string temp = str.substr(1);
        reverse(temp.begin(), temp.end());
        dfs(temp);
    }

    if(str[str.size()-1] == 'A') dfs(str.substr(0, str.size()-1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;
    cin >> T;

    dfs(T);
    cout << flag;
}