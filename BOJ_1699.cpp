#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    int arr[N+1];
    int dp[N+1];
    for(int i = 0; i <= N; i++) {
        arr[i] = i*i;
        dp[i] = INT_MAX;
    }
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= N; i++) {
        for(int j = 1; j <= sqrt(i); j++) {
            dp[i] = min(dp[i], dp[i-arr[j]]+1);
        }
    }
    cout << dp[N];
}