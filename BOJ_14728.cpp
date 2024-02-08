#include <iostream>

using namespace std;

int main() {
    int N, T;
    int dp[101][10001];
    int K[101], S[101];

    cin >> N >> T;

    for(int i = 1; i <= N; i++) {
        cin >> K[i] >> S[i];
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= T; j++) {
            if(K[i] <= j) dp[i][j] = max(dp[i-1][j], dp[i-1][j-K[i]] + S[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[N][T];
}