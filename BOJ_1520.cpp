#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAX 500

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int M, N;
int map[MAX][MAX];
int dp[MAX][MAX];

int dfs(int x, int y) {
    if(x == M-1 && y == N-1) return 1;
    if(dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 0;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
        if(map[nx][ny] < map[x][y]) dp[x][y] += dfs(nx, ny);
    }
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(0, 0);
}