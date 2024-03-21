#include<vector>
#include<queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visited[101][101];

int solution(vector<vector<int> > maps)
{
    int width = maps[0].size();
    int height = maps.size();
    
    queue<pair<int, pair<int, int>>> q;
    q.push({1, {0, 0}});
    visited[0][0] = true;
    
    while(!q.empty()) {
        pair<int,pair<int, int>> cur = q.front();
        q.pop();
        
        if(cur.second.first == width-1 && cur.second.second == height-1) {
            return cur.first;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.second.first;
            int ny = dy[i] + cur.second.second;
            int dist = cur.first;        
            
            if(nx < 0 || ny < 0 || nx >= width || ny >= height) continue;
            if(maps[ny][nx] == 1 && !visited[ny][nx]) {
                q.push({dist+1, {nx, ny}});
                visited[ny][nx] = true;
            }
        }
    }
    
    return -1;
}
