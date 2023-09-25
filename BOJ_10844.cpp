#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    if(N==1){
        cout << 9;
        return 0;
    }
    int dp[N+1][10];
    dp[1][0] = 0;
    dp[2][0] = 1;
    for(int i=1; i<10; i++){
        dp[1][i] = 1;
        dp[2][i] = dp[1][i] + dp[1][i-1];
    }
    dp[2][9] = 1;

    for(int i=3; i<=N; i++){
        for(int j=0; j<10; j++){
            if(j==0){
                dp[i][j] = dp[i-1][1]%1000000000;
            }else if(j==9){
                dp[i][j] = dp[i-1][8]%1000000000;
            }else{
                dp[i][j] = dp[i-1][j-1]%1000000000 + dp[i-1][j+1]%1000000000;
            }
        }
    }
    long long result = 0;
    for(int i=0; i<10; i++){
        result += dp[N][i];
    }
    cout << result%1000000000;
}