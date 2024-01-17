#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, temp, cnt = 1, answer = 1;
    vector<int> vec;
    cin >> N >> M;

    int dp[41];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= 40; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    if(M == 0) {
        cout << dp[N];
        return 0;
    }

    for(int i = 0; i < M; i++) {
        cin >> temp;
        vec.push_back(temp - cnt);
        cnt = temp + 1;
        if(i == M-1 && temp < N) {
            vec.push_back(N - temp);
        }
    }

    for(auto &i : vec) {
        answer *= dp[i];
    }
    cout << answer;
}