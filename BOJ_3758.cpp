#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

#define MAX 101

using namespace std;

struct Team {
    int question[MAX];
    int cnt = 0;
    int sum = 0;
    int id;
    int lastSubmit;
};

bool cmp(const Team& a, const Team& b) {
    if(a.sum == b.sum && a.cnt == b.cnt) {
        return a.lastSubmit < b.lastSubmit;
    }
    if (a.sum == b.sum) {
        return a.cnt < b.cnt;
    }
    return a.sum > b.sum;
}

int main() {
    int T;

    cin >> T;
    vector<int> answer;
    
    for(int i = 0; i < T; i++) {
        int n, k, t, m;
        Team *team = new Team[MAX];

        cin >> n >> k >> t >> m;

        int id, num, score;
        int index = 0;
        for(int j = 0; j < m; j++) {
            cin >> id >> num >> score;
            if(id > index) index = id;
            team[id].id = id;
            if(team[id].question[num] < score) {
                team[id].sum -= team[id].question[num];
                team[id].sum += score;
                team[id].question[num] = score;
            }
            team[id].lastSubmit = j;
            team[id].cnt++; 
        }

        sort(team, team+index+1, cmp);

        for(int j = 0; j <= index; j++) {
            if(team[j].id == t) {
                answer.push_back(j+1);
                break;
            }
        }
    }

    for(auto &i : answer) cout << i << endl;
}