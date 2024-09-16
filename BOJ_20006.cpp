#include <iostream>
#include <map>
#include <deque>
#include <string>

using namespace std;

int main() {
    int p, m;
    cin >> p >> m;
    
    string nickname;
    int level;
    deque<pair<string, int>> q1;
    deque<pair<string, int>> q2;

    for(int i = 0; i < p; i++) {
        cin >> level >> nickname;
        q1.push_back({nickname, level});
    }

    map<string, int> mp;
    int temp;

    while(true) {
        if(mp.empty()) {
            mp.insert(q1.front());
            temp = q1.front().second;
            q1.pop_front();
        } else if(mp.size() == m) {
            cout << "Started!" << endl;
            for(auto &i : mp) cout << i.second << " " << i.first << endl;
            mp.clear();
            while(!q2.empty()) {
                q1.push_front(q2.front());
                q2.pop_front();
            }
        } else if(q1.empty()) {
            cout << "Waiting!" << endl;
            for(auto &i : mp) cout << i.second << " " << i.first << endl;
            mp.clear();
            while(!q2.empty()) {
                q1.push_front(q2.front());
                q2.pop_front();
            }
        } else {
            pair<string, int> cur = q1.front();
            if(cur.second >= temp-10 && cur.second <= temp+10) {
                mp.insert(cur);
                q1.pop_front();
            } else {
                q2.push_front(cur);
                q1.pop_front();
            }
        }
        if(q1.empty() && q2.empty() && mp.empty()) break;
    }
}