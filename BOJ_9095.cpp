#include <iostream>

using namespace std;

int dp[11];

int main(){
    int T, n;
    cin >> T;
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for(int i=0; i<T; i++){
        cin >> n;
        for(int i=4; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout << dp[n] << endl;
    }
}
