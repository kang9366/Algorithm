#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <cstring>

#define MAX 50

using namespace std;

typedef pair<int, int> coordinate;

int N, M;
int arr[MAX][MAX][4];
bool visited[MAX][MAX];
int temp[MAX][MAX];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<int> vec;
vector<coordinate> cor;

int bfs(int x, int y, int num) {
    queue<coordinate> q;
    q.push({x, y});
    int cnt = 1;
    temp[x][y] = num;

    while(!q.empty()) {
        coordinate cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(!visited[nx][ny] && arr[cur.first][cur.second][i] == 0) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                cnt++;
                temp[nx][ny] = num;
            }
        }
    }
    return cnt;
}

set<int> test(int x, int y, int s) {
    queue<coordinate> q;
    set<int> st;

    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        coordinate cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(!visited[nx][ny]) {
                if(temp[nx][ny] == s) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                } else {
                    st.insert(temp[nx][ny]);
                }
            }
        }
    }
    return st;
}


int main() {
    cin >> N >> M;

    int num;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> num;
            for(int k = 3; k >= 0; k--) {
                arr[i][j][3-k] = (num >> k) & 1;
            }
        }
    }

    int cnt = 0;
    int value = 0;
    int idx = 0;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j]) {
                visited[i][j] = true;
                int area = bfs(i, j, idx++);
                value = max(value, area);

                vec.push_back(area);
                cor.push_back({i, j});
                cnt++;
            }
        }
    }

    int tmp = 0;
    for(int i = 0; i < vec.size(); i++) {
        memset(visited, false, sizeof(visited));
        set<int> s = test(cor[i].first, cor[i].second, i);
        for(auto iter = s.begin(); iter != s.end(); iter++) {
            tmp = max(tmp, vec[i] + vec[*iter]);
        }
    }

    cout << cnt << endl;
    cout << value << endl;
    cout << tmp;
}