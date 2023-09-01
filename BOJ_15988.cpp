#include <iostream>
#define MOD 1000000009
#define endl "\n"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, n;
    long long dp[1000010];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> n;
        for(int j=3; j<=n; j++){
            dp[j] = (dp[j-1] + dp[j-2] + dp[j-3])%MOD;  
        }
        cout << dp[n]%MOD << endl;
    }
}