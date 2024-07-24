#include <iostream>

#define MAX 100001

using namespace std;

int dp[MAX] = {0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for(int i = N-1; i >= 0; i--) dp[i] = N-i;

    for(int i = N+1; i <= K; i++) {
        if (i % 2 == 0) dp[i] = min(dp[i-1],  dp[i/2]) + 1;
        else dp[i] = min(dp[i-1], dp[(i+1)/2]+1) + 1;
    }

    cout << dp[K];
}