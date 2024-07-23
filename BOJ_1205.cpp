#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, P;
    map<int, int, greater<int>> m;

    cin >> N >> M >> P;

    if(N == 0) {
        cout << 1;
        return 0;
    }

    for(int i = 0; i < N+1; i++) {
        int score;

        if(i == N) score = M;
        else cin >> score;

        auto iter = m.find(score);

        if(iter != m.end()) m[score]++;
        else m.insert({score, 1});
    }

    map<int, int>::iterator iter = m.begin();
    int temp = 0;
    int answer = 0;

    for(int i = 0; i < P;) {
        answer += iter->second;
        i += iter->second;
        if(iter->first != M && answer >= P) {
            answer = -1;
            break;
        } else if(iter->first == M) {
            if(iter->second > 1 && answer > P) answer = -1;
            else if(iter->second > 1) answer -= iter->second-1;
            break;
        }
        iter++;
    }

    if(answer == 0) {
        cout << -1;
    } else {
        cout << answer;
    }
}