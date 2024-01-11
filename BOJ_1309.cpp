#include <iostream>
#define MOD 9901

using namespace std;

int main() {
    int N;
    cin >> N;
    int dp[N+1][4];

    if(N==1) {
        cout << 3;
        return 0;
    }
    
    dp[2][1] = 2;
    dp[2][2] = 2;
    dp[2][3] = 3; 

    for(int i = 3; i <= N; i++) {
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
        dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % MOD;
        dp[i][3] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][3]) % MOD;
    }

    cout << (dp[N][1] + dp[N][2] + dp[N][3]) % MOD << endl;
}