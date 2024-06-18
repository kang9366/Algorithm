#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N, H, T, K;
    priority_queue<int> pq;

    cin >> N >> H >> T;

    for(int i = 0; i < N; i++) {
        cin >> K;
        pq.push(K);
    }

    int answer = 0;

    for(int i = 0; i < T; i++) {
        int h = pq.top();

        if(H > h) {
            cout << "YES" << endl << i;
            return 0;
        } else if (h > 1) {
            pq.pop();
            pq.push(h/2);
        }
    }

    if(H <= pq.top()) {
        cout << "NO" << endl << pq.top();
    } else {
        cout << "YES" << endl << T;
    }
}