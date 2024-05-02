#include <iostream>
#include <algorithm>

#define MAX 101

using namespace std;

long long dp[MAX];

int main() {
    int N;
    cin >> N;

    dp[1] = 1;

    for(int i = 2; i <= N; i++) {
        dp[i] = max(dp[i-1] + 1, dp[i-2] + 2);
        for(int j = 3; j < i; j++) {
            dp[i] = max(dp[i], dp[i-j]*(j-1));
        }
    }
    cout << dp[N];
}
