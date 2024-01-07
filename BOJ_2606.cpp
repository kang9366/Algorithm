#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> graph;
vector<bool> isVisit;

int main() {
    int v, e, ans = 0;
    cin >> v >> e;
    graph.assign(v+1, vector<int> (0, 0));
    isVisit.assign(v+1, false);

    for(int i=0; i<e; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].emplace_back(e);
        graph[e].emplace_back(s);
    }
    
    stack<int> s;
    s.push(1);
    isVisit[1] = true;
    
    while(!s.empty()) {
        int cur = s.top();
        s.pop();
        
        ans++;
        for(int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            if(!isVisit[next]) {
                s.push(next);
                isVisit[next] = true;
            }
        }
    }

    cout << ans-1;
}