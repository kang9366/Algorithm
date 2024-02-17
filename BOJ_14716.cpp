#include <iostream>
#include <queue>

#define MAX 250

using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = { 1, -1, 0, 0, 1 , 1, -1, -1 };
int M, N;

void bfs() {
    int answer = 0;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] == 1 && !visited[i][j]) {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while(!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for(int k = 0; k < 8; k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
                        if(map[nx][ny] == 1 && !visited[nx][ny]) {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
                answer++;
            }
        }
    }
    cout << answer;
}

int main() {
    cin >> M >> N;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    bfs();
}