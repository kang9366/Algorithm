#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, time, score, flag, answer = 0;
    cin >> N;

    stack<int> s1, s2;

    for(int i = 0; i < N; i++) {
        cin >> flag;
        if(flag) {
            cin >> score >> time;
            time--;
            if(time == 0) {
                answer += score;
                continue;
            }
            s1.push(time);
            s2.push(score);
        } else {
            if(s1.empty()) continue;
            s1.top()--;
            if(s1.top() == 0) {
                answer += s2.top();
                s1.pop();
                s2.pop();
            }
        }
    }
    cout << answer;
}