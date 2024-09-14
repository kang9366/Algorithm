#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    static bool visited[1000001];
    static int cnt[1000001];

    queue<int> q;
    q.push(S);

    int answer = 0;
    visited[S] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if(cur == G) {
            cout << cnt[cur];
            return 0;
        }

        if(cur + U <= F && !visited[cur+U]) {
            q.push(cur+U);
            visited[cur+U] = true;
            cnt[cur+U] = cnt[cur]+1;
        }
        if(cur - D >= 1 && !visited[cur-D]) {
            q.push(cur - D);
            visited[cur-D] = true;
            cnt[cur-D] = cnt[cur]+1;
        }
    }
    cout << "use the stairs";
}