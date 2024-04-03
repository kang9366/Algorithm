#include <iostream>
#include <queue>
#include <vector>

#define MAX 101

using namespace std;

int W, H;
int map[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {false,};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
pair<int, int> answer = {0, 0};

void bfs() {
    queue<pair<int, int>> q;
    queue<pair<int, int>> temp;
    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        if(map[cur.first][cur.second] != 0) continue;
        
        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;

            if(nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
            if(map[ny][nx] == 1 && !visited[ny][nx]) {
                temp.push({0, 0});
            } else if(map[ny][nx] == 0 && !visited[ny][nx]) {
                q.push({nx, ny});
            }
            visited[ny][nx] = true;
        }
        answer.first++;
    }
}

int main() {
    cin >> H >> W;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> map[i][j];
        }
    }
    bfs();
    cout << answer.first << "\n" << answer.second;
}