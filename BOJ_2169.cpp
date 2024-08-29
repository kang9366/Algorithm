#include <iostream>
#include <climits>

#define MAX 1000

using namespace std;

int N, M;
int map[MAX][MAX];
int dp[MAX][MAX];
int temp[MAX][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            dp[i][j] = INT_MIN;
        }
    }

    dp[0][0] = map[0][0];
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            for(int j = 1; j < M; j++) dp[i][j] = map[i][j] + dp[i][j-1];
        } else {
            temp[M-1][0] = dp[i-1][M-1] + map[i][M-1];
            temp[0][1] = dp[i-1][0] + map[i][0];
            
            for(int j = M-2; j >= 0; j--) temp[j][0] = max(dp[i-1][j], temp[j+1][0]) + map[i][j];
            for(int j = 1; j < M; j++) temp[j][1] = max(dp[i-1][j], temp[j-1][1]) + map[i][j];
            for(int j = 0; j < M; j++) dp[i][j] = max(temp[j][0], temp[j][1]);
        }
    }

    cout << dp[N-1][M-1];
}