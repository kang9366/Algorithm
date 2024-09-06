#include <iostream>
#include <queue>
#include <cstring>

#define MAX 50

using namespace std;

typedef pair<int, int> coordinate;

int N, L, R;
int map[MAX][MAX];
bool visited[MAX][MAX];
int group[MAX][MAX];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int check = 0;

void bfs(int x, int y) {
    group[x][y] = true;
    queue<coordinate> q;
    vector<coordinate> vec;

    q.push({x, y});
    vec.push_back({x, y});

    int cnt = 1;
    int sum = map[x][y];

    while(!q.empty()) {
        coordinate cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            int diff = abs(map[nx][ny] - map[cur.first][cur.second]);
            if(diff >= L && diff <= R && !group[nx][ny]) {
                q.push({nx, ny});
                group[nx][ny] = true;
                sum += map[nx][ny];
                cnt++;
                vec.push_back({nx, ny});
                check++;
            }
        }
    }

    int population = sum / cnt;
    for(auto &i : vec) map[i.first][i.second] = population;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    cin >> N >> L >> R;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cin >> map[i][j];
    }

    int answer = 0;
    while(true) {
        check = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(!group[i][j]) bfs(i, j);
            }
        }
        if(check == 0) break;
        memset(group, false, sizeof(group));
        answer++;
    }

    cout << answer;
}