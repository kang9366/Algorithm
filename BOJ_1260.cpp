#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> vec[1001];
bool check[1001] = {false};

void dfs(int V){
    check[V] = true;
    cout << V << " ";
    for(int i=0; i<vec[V].size(); i++){
        int next = vec[V][i];
        if(!check[next]){
            dfs(next);
        }
    }
}

void bfs(int V){
    queue<int> q;
    q.push(V);
    check[V] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(int i=0; i<vec[cur].size(); i++){
            int next = vec[cur][i];
            if(!check[next]){
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, V, from, to;
    
    cin >> N >> M >> V;
    
    for(int i=0; i<M; i++){
        cin >> from >> to;
        vec[from].push_back(to);
        vec[to].push_back(from);
    }
    
    for(int i=1; i<=N; i++){
        sort(vec[i].begin(), vec[i].end());
    }
    
    dfs(V);
    memset(check, false, sizeof(check));
    cout << endl;
    bfs(V);
}
