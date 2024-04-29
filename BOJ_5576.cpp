#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int W[10];
    int K[10];

    for(int i = 0; i < 10; i++) {
        cin >> W[i];
    }

    for(int i = 0; i < 10; i++) {
        cin >> K[i];
    }

    sort(W, W + 10, greater<>());
    sort(K, K + 10, greater<>());

    cout << W[0] + W[1] + W[2] << " " << K[0] + K[1] + K[2];
}
