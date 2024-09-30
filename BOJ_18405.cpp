#include <iostream>
#include <vector>
#include <queue>
#include <set>

#define MAX 200

using namespace std;

typedef pair<int, int> coordinate;

queue<coordinate> q;

int N, K;
int S, X, Y;
int arr[MAX][MAX];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs() {
    int size = q.size();
    set<coordinate> s;
    
    while(size--) {
        coordinate cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(arr[nx][ny] == 0) {
                arr[nx][ny] = arr[cur.first][cur.second];
                q.push({nx, ny});
                s.insert({nx, ny});
            }
            else if(s.find({nx, ny}) != s.end() && arr[cur.first][cur.second] < arr[nx][ny]) {
                arr[nx][ny] = arr[cur.first][cur.second];
                q.push({nx, ny});
                s.insert({nx, ny});
            }
        }
    }
}

int main() {
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if(arr[i][j] != 0) q.push({i, j});
        }
    }

    cin >> S >> X >> Y;
    for(int i = 0; i < S; i++) bfs();
    cout << arr[X-1][Y-1];
}