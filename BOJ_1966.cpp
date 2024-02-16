#include <iostream>
#include <queue>
#include <string>

#define MAX 101

using namespace std;

int map[MAX][MAX];
int visited[MAX][MAX];
int answer[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int N, M;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    answer[x][y] = 1;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 1 || ny < 1 || nx > N || ny > M) continue;
            if(!visited[nx][ny] && map[nx][ny] == 1) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                answer[nx][ny] = answer[cur.first][cur.second] + 1;
                // cout << nx << " " << ny << " " << answer[nx][ny] << endl;
                // if(nx == N && ny == M) cout << answer[nx][ny];
            }
        }
    }
}

int main() {
    cin >> N >> M;
    string temp;

    for(int i = 1; i <= N; i++) {
        cin >> temp;
        for(int j = 1; j <= M; j++) {
            map[i][j] = temp[j-1] - '0';
        }
    }

    bfs(1, 1);
    cout << answer[N][M];
}