#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 12

using namespace std;

int R, C;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<string> map;
vector<pair<int, int>> vec;
vector<pair<int, int>> temp;

void solution() {
    bool visited[R+2][C+2];
    queue<pair<int, int>> q;
    memset(visited, false, sizeof(visited));

    for(int i = 1; i < R+1; i++) {
        for(int j = 1; j < C+1; j++) {
            if(map[i][j] == 'X') {
                int cnt = 0;
                for(int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(map[nx][ny] == '.') cnt++;
                }
                if(cnt < 3) {
                    vec.push_back({i, j});
                } else {
                    temp.push_back({i, j});
                }
            }
        }
    }

    int minX = vec[0].second;
    int minY = vec[0].first;
    int maxX = vec[0].second;
    int maxY = vec[0].first;

    for(auto&i : vec) {
        minX = min(minX, i.second);
        minY = min(minY, i.first);
        maxX = max(maxX, i.second);
        maxY = max(maxY, i.first);
    }

    for(auto&i : temp) {
        map[i.first][i.second] = '.';
    }

    for(int i = minY; i <= maxY; i++) {
        for(int j = minX; j <= maxX; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

int main() {
    string str;
    cin >> R >> C;

    string temp = "";
    for(int i = 0; i < C+2; i++) {
        temp += '.';
    }

    map.push_back(temp);
    for(int i = 0; i < R; i++) {
        cin >> str;
        str = '.' + str + '.';
        map.push_back(str);
    }
    map.push_back(temp);
    solution();
}