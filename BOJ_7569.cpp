#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define MAX 100

using namespace std;

typedef tuple<int, int, int> coordinate;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dz[3] = {1, -1};

int M, N, H;
int map[MAX][MAX][MAX];
queue<coordinate> q;

void bfs() {
    int answer = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++) {
            coordinate cur = q.front();
            q.pop();

            for(int j = 0; j < 4; j++) {
                int nx = dx[j] + get<1>(cur);
                int ny = dy[j] + get<2>(cur);
                int z = get<0>(cur);

                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if(map[z][nx][ny] == 0) {
                    map[z][nx][ny] = 1;
                    q.push({z, nx, ny});
                }
            }
            for(int j = 0; j < 2; j++) {
                int x = get<1>(cur);
                int y = get<2>(cur);
                int nz = dz[j] + get<0>(cur);
                if(nz < 0 || nz >= H) continue;
                if(map[nz][x][y] == 0) {
                    map[nz][x][y] = 1;
                    q.push({nz, x, y});
                }
            }
        }
        answer++;
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(map[i][j][k] == 0) {
                    cout << -1;
                    return;
                }
            }
        }
    }

    cout << --answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                cin >> map[i][j][k];
                if(map[i][j][k] == 1) q.push({i, j, k});
            }
        }
    }

    bfs();
}