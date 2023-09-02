#include <iostream>


using namespace std;

int main(){
    int N;
    cin >> N;

    int dp[N];

    for(int i=0; i<N; i++){
        cin >> dp[i];
    }

    int result = dp[0];
    for(int i=1; i<N; i++){
        dp[i] = max(dp[i], dp[i] + dp[i-1]);
        result = max(result, dp[i]);
    }

    cout << result;
}