#include <iostream>
#include <vector>
#include <algorithm>
#include<string.h>

using namespace std;

int dx[2] = {1, 0};
int dy[2] = {0, -1};

int main() {
    int N, M;
    cin >> N >> M;
    int dp[N+1][M+1];
    int map[N+1][M+1];

    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + map[i][j];
        }
    }
    cout << dp[N][M];
}