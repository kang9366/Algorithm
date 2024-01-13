#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 101

using namespace std;

int arr[MAX][MAX] = {0, };
bool visited[MAX][MAX];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

queue<pair<int, int>> q;
vector<int> answer;

int M, N, K;

void solution() {
    int cnt = 0;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            int area = 1;
            if(visited[i][j] || arr[i][j] == 1) continue;
            cnt++;
            
            visited[i][j] = true;
            q.push({i, j});

            while(!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];

                    if(nx < 0 || nx >= M) continue;
                    if(ny < 0 || ny >= N) continue;

                    if(!visited[nx][ny] && arr[nx][ny] == 0) {
                        area++;
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            answer.push_back(area);
        }
    }
    sort(answer.begin(), answer.end());
    cout << cnt << "\n";

    for(auto&i : answer) {
        cout << i << " ";
    }
}

int main() {
    int x1, y1, x2, y2;
    cin >> M >> N >> K;

    for(int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1; j < x2; j++) {
            for(int k = M-y2; k < M-y1; k++) {
                arr[k][j] = 1;
            }
        }
    }

    solution();
}