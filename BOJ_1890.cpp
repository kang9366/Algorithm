#include <iostream>
#include <climits>

#define MAX 100

using namespace std;

typedef long long ll;

int N;

ll dp[MAX][MAX];
int map[MAX][MAX];

int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

ll dfs(int x, int y) {
    if(x == N-1 && y == N-1) return 1;
    if(map[x][y] == 0) return 0;
    if(dp[x][y] != 0) return dp[x][y];

    for(int i = 0; i < 2; i++) {
        int nx = x;
        int ny = y;
        if(dx[i] == 0) ny += map[x][y];
        if(dy[i] == 0) nx += map[x][y];
        
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        dp[x][y] += dfs(nx, ny);
    }
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cin >> map[i][j];
    }
    cout << dfs(0, 0) << endl;
}