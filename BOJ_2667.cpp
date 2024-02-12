#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 26

using namespace std;

int N;
int arr[26][26];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool visited[26][26] = { false };
vector<int> answer;

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});

    visited[i][j] = true;
    int cnt = 1;

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for(int k = 0; k < 4; k++) {
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];

            if(nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny] && arr[nx][ny] == 1) {
                cnt++;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    answer.push_back(cnt);
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j] && arr[i][j] == 1) {
                bfs(i, j);
            }
        }
    }

    sort(answer.begin(), answer.end());

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
}