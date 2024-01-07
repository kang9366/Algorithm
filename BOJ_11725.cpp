#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001

using namespace std;

int ans[MAX];
bool isVisit[MAX];
vector<int> graph[MAX];

int main() {
    int N;
    cin >> N;

    for(int i=0; i<N-1; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].emplace_back(e);
        graph[e].emplace_back(s);
    }

    queue<int> q;
    q.push(1);
    isVisit[1] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];
            if(!isVisit[next]) {
                q.push(next);
                isVisit[next] = true;
                ans[next] = cur;
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << ans[i] << "\n";
    }
}