#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <cstring>

#define MAX 300

using namespace std;

typedef pair<int, int> coordinate;

int board[MAX][MAX];
bool visited[MAX][MAX];
map<coordinate, int> m;

int answer = 0;
int cnt = 0;
int N, M;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void melt(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if(board[nx][ny] == 0) {
            if(m.find({x, y}) != m.end()) m[{x, y}]++;
            else m.insert({{x, y}, 1});
        }
    }
}

void bfs(int x, int y) {
    if(visited[x][y]) return;
    queue<coordinate> q;
    q.push({x, y});

    while(!q.empty()) {
        coordinate cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + *(dx+i);
            int ny = cur.second + *(dy+i);

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(board[nx][ny] != 0  && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    cnt++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    while(true) {
        memset(visited, false, sizeof(visited));
        m.clear();
        cnt = 0;
        vector<coordinate> vec;
        bool flag = false;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(board[i][j] != 0) {
                    if(!visited[i][j]) vec.push_back({i, j});
                    melt(i, j);
                    flag = true;
                }
            }
        }

        if(!flag) {
            cout << 0;
            break;
        }
        for(auto &i : vec) bfs(i.first, i.second);
        if(cnt >= 2) {
            cout << answer;
            break;
        }
        
        ;
        for(map<coordinate, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
            int x = iter->first.first;
            int y = iter->first.second;
            int num = iter->second;
            board[x][y] -= num;
            if(board[x][y] < 0) board[x][y] = 0;
        }
        answer++;
    }
}