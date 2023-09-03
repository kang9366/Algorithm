#include <iostream>

using namespace std;

long long solve(int N){
    long long dp[N+1][11];
    
    for(int i=1; i<=10; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=N; i++){
        for(int j=1; j<=10; j++){
            if(j==1){
                dp[i][j] = 1;
            }else{
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
    }

    long long result = 0;
    for(int i=1; i<=10; i++){
        result += dp[N][i];
    }
    return result;
}

int main(){
    int N, T;
    cin >> T;


    for(int i=0; i<T; i++){
        cin >> N;
        cout << solve(N);
    }
}