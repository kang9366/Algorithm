#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        map<int, int> m;
        int arr[N];
        for(int i = 0; i < N; i++) {
            cin >> arr[i];
            if(m.find(arr[i]) != m.end()) m[arr[i]]++;
            else m.insert({arr[i], 1});
        }

        vector<int> temp;
        for(auto iter = m.begin(); iter != m.end(); iter++) {
            if(iter->second < 6) temp.push_back(iter->first);
        }

        for(int &i : temp) m.erase(i);
        int score = 1;
        map<int, vector<int>> answer;
        for(auto iter = m.begin(); iter != m.end(); iter++) answer.insert({iter->first, vector<int>(3, 0)});
        for(int i = 0; i < N; i++) {
            if(m.find(arr[i]) != m.end()) {
                if(answer[arr[i]][0]++ < 4) answer[arr[i]][1] += score;
                if(answer[arr[i]][0] == 5) answer[arr[i]][2] = score;
                score++;
            }
        }

        int team_num;
        int max_score = INT_MAX;
        int five = 0;
        for(auto iter = answer.begin(); iter != answer.end(); iter++) {
            if(iter->second[1] < max_score) {
                max_score = iter->second[1];
                five = iter->second[2];
                team_num = iter->first;
            } else if(iter->second[1] == max_score) {
                if(iter->second[2] < five) {
                    max_score = iter->second[1];
                    five = iter->second[2];
                    team_num = iter->first;
                }
            }
        }
        cout << team_num << endl;
    }
}