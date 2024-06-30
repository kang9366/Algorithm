#include <iostream>
#include <queue>

#define MAX 1024

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int arr[MAX][MAX];
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    while(N > 1) {
        for(int i = 0; i < N; i+=2) {
           for(int j = 0; j < N; j+=2) {
                priority_queue<int> pq;
                pq.push(arr[i][j]);
                pq.push(arr[i][j+1]);
                pq.push(arr[i+1][j]);
                pq.push(arr[i+1][j+1]);
                pq.pop();
                arr[i/2][j/2] = pq.top();
            }
        }
        N/=2;
    }
    cout << arr[0][0];
}