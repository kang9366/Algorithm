#include <iostream>

#define MAX 91

using namespace std;

long long dp[MAX][2];

int main() {
    int N;
    cin >> N;

    dp[1][0] = 0;
    dp[1][1] = 1;

    for(int i = 2; i <= N; i++) {
        for(int j = 0; j < 2; j++) {
            if(j == 0) {
                dp[i][j] = dp[i-1][1] + dp[i-1][0];
            } else if(j == 1) {
                dp[i][j] = dp[i-1][0];
            }
        }
    }
    cout << dp[N][0] + dp[N][1];
}
