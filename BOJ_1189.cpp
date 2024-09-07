#include <iostream>

#define MAX 5

using namespace std;

int R, C, K;

char map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int answer = 0;

void dfs(int x, int y, int cnt) {
    if(x==0 && y==C-1) {
        if(cnt == K) answer++;
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
        if(map[nx][ny] != 'T' && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, cnt+1);
            visited[nx][ny] = false;
        }
    }
    
}

int main() {
    cin >> R >> C >> K;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) cin >> map[i][j];
    }
    
    visited[R-1][0] = true;
    dfs(R-1, 0, 1);
    cout << answer;
}