#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX 100
#define endl \n

using namespace std;

int N;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int answer = 0;

void bfs(int n, int x, int y) {
    queue<pair<int, int>> q;

    q.push({x, y});
    

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(!visited[nx][ny] && map[nx][ny] > n) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int M = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j] > M) M = map[i][j];
        }
    }

    for(int i = 0; i < M; i++) {
        memset(visited, false, sizeof(visited));
        int cnt = 0;
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                if(map[j][k] > i && !visited[j][k]) {
                    bfs(i, j, k);
                    visited[j][k] = true;
                    cnt++;
                }
            }
        }
        if(cnt > answer) answer = cnt;
    }
    cout << answer;
}