#include <iostream>

#define MAX 100001
#define MOD 1000000009

using namespace std;

long long dp[MAX][4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n;
    cin >> T;
    
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;

    dp[2][1] = 0;
    dp[2][2] = 1;
    dp[2][3] = 0;

    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for(int i = 0; i < T; i++) {
        cin >> n;
        for(int i = 4; i <= n; i++) {
            dp[i][1] = (dp[i-1][2] + dp[i-1][3])%MOD;
            dp[i][2] = (dp[i-2][1] + dp[i-2][3])%MOD;
            dp[i][3] = (dp[i-3][1] + dp[i-3][2])%MOD;
        }
        cout << (dp[n][1] + dp[n][2] + dp[n][3])%MOD << "\n";
    }
}
