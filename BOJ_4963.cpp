#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 50

using namespace std;

int dx[] = {0,0,-1,1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,-1,1};
int maps[MAX][MAX];
bool visited[MAX][MAX];
int w, h;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;


    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i = 0; i < 8; i++) {
            int nx = dx[i] + cur.first;
            int ny = dx[i] + cur.second;
            
            if(nx >= 0 && nx < w && ny >=0 && ny < h){
                if(!visited[ny][nx] && maps[ny][nx] == 1){
                    q.push(make_pair(nx, ny));
                    visited[ny][nx] = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true) {
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        queue<pair<int, int>> temp;
        
        memset(visited, false , sizeof(visited));
        memset(maps, 0, sizeof(maps));

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> maps[i][j];
            }
        }

        int cnt = 0;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(maps[i][j] == 1 && !visited[i][j]) {
                    cnt++;
                    bfs(i, j);
                }
            }
        }
        cout << cnt << endl;
    }
}
