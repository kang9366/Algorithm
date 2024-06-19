#include <iostream>
#include <queue>
#include <numeric>
#include <cstring>

using namespace std;

int main() {
    int n, w, L, truck, answer = 0;
    int exit = 0;
    queue<int> q;

    cin >> n >> w >> L;

    int bridge[w];
    memset(bridge, 0, sizeof(bridge));

    for(int i = 0; i < n; i++) {
        cin >> truck;
        q.push(truck);
    }

    while(exit != n) {
        int current = 0;
        answer++;
        
        for(int i = w-1; i >= 0; i--) {
            if(i == w-1) {
                if(bridge[i] != 0) {
                    bridge[i] = 0;
                    exit++;
                }
            } else {
                if(bridge[i] != 0) {
                    bridge[i+1] = bridge[i];
                    bridge[i] = 0;
                    current++;
                }
            }
        }

        if(q.empty()) {
            continue;
        }

        if(accumulate(bridge, bridge + w, 0) + q.front() <= L && current < w) {
            bridge[0] = q.front();
            q.pop();
        }
    }

    cout << answer;
}