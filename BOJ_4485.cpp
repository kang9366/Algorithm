#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

#define MAX 125
#define MAX_VALUE 10000000
#define endl "\n"

using namespace std;

typedef pair<int, int> coordinate;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int map[MAX][MAX];
int answer[MAX][MAX];
int N;

int bfs() {
    queue<coordinate> q;
    q.push({0, 0});
    answer[0][0] = map[0][0];

    while(!q.empty()) {
        coordinate cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            int temp = answer[cur.first][cur.second] + map[nx][ny];
            if(answer[nx][ny] > temp) {
                answer[nx][ny] = temp;
                q.push({nx, ny});
            }
        }
    }
    return answer[N-1][N-1];
}

int main() {
    int cnt = 1;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true) {
        cin >> N;
        if(N==0) break;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> map[i][j];
                answer[i][j] = MAX_VALUE;
            }
        }

        cout << "Problem " << cnt++ << ": " << bfs() << endl;
    }
}