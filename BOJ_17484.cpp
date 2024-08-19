#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int map[N][M];
    int dp[N][M][3];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(i==0) {
                for(int k = 0; k < 3; k++) dp[i][j][k] = map[i][j];
            } else {
                for(int k = 0; k < 3; k++) dp[i][j][k] = INT_MAX;
            }
        }
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(j == 0) {
                dp[i][j][1] = map[i][j] + dp[i-1][j][2];
                dp[i][j][2] = map[i][j] + min(dp[i-1][j+1][0], dp[i-1][j+1][1]);
            } else if(j == M-1) {
                dp[i][j][0] = map[i][j] + min(dp[i-1][j-1][1], dp[i-1][j-1][2]);
                dp[i][j][1] = map[i][j] + dp[i-1][j][0];
            } else {
                dp[i][j][0] = map[i][j] + min(dp[i-1][j-1][1], dp[i-1][j-1][2]);
                dp[i][j][1] = map[i][j] + min(dp[i-1][j][0], dp[i-1][j][2]);
                dp[i][j][2] = map[i][j] + min(dp[i-1][j+1][0], dp[i-1][j+1][1]);
            }
        }
    }

    int answer = INT_MAX;
    for(int i = 0; i < M; i++) {
        int temp = *min_element(dp[N-1][i], dp[N-1][i]+3);
        answer = min(answer, temp);
    }
    cout << answer;
}