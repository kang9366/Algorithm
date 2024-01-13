#include <iostream>
#include <vector>
#include <queue>

#define MAX 501

using namespace std;

int arr[MAX][MAX];
bool visited[MAX][MAX];
vector<int> answer;
queue<pair<int, int>> q;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m;

void bfs() {
    int max = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int area = 1;
            if(visited[i][j] || arr[i][j] == 0) continue;
            cnt++;
            visited[i][j] = true;
            q.push({i, j});

            while(!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx < 1 || nx > n) continue;
                    if(ny < 1 || ny > m) continue;
                    
                    int next = arr[nx][ny];
                    if(next==1 && !visited[nx][ny]) {
                        area++;
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            if(area > max) max = area;
        }
    }
    cout << cnt << "\n";
    cout << max;
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    bfs();
}