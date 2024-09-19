#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        int coin[N+1];
        for(int i = 1; i <= N; i++) cin >> coin[i];

        int M;
        cin >> M;
        int dp[M+1][N+1];

        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) {
                if(i < coin[j]) dp[i][j] = dp[i][j-1];
                else {
                    int temp;
                    if(i-coin[j] == 0) temp = 1;
                    else temp = dp[i-coin[j]][j];
                    dp[i][j] = temp + dp[i][j-1];
                }
            }
        }
        cout << dp[M][N] << endl;
    }
}