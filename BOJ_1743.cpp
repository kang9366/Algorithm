#include <iostream>
#include <vector>
#include <stack>

#define MAX 102

using namespace std;    

int N, M;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int result = 0;
int map[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int i, int j) {
    int cnt = 1;
    stack<pair<int, int>> s;
    s.push({j, i});
    visited[j][i] = true;

    while(!s.empty()) {
        pair<int, int> cur = s.top();
        s.pop();

        for(int k=0; k<4; k++) {
            int x = cur.first + dy[k];
            int y = cur.second + dx[k];

            if(x < 1 || y < 1 || x > M+1 || y > N+1) continue;
            
            if(map[x][y]==1 && !visited[x][y]) {
                s.push({x, y});
                visited[x][y] = true;
                cnt++;
            }
        }
    }
    if(cnt>result) result = cnt;
}

int main() {
    int K, r, c;
    cin >> N >> M >> K;

    for(int i=0; i<K; i++) {
        cin >> r >> c;
        map[c][r] = 1;
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(map[j][i] == 1 && !visited[j][i]) {
                dfs(i, j);
            }
        }
    }

    cout << result;
}