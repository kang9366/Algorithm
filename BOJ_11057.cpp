#include <iostream>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N=0, result;
    cin >> N;

    int dp[1001][10];

    for(int i=0; i<10; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=N; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<=j; k++){
                dp[i][j] += dp[i-1][k];
            }
            dp[i][j] %= 10007;
        }
    }

    for(int i=0; i<10; i++){
        result += dp[N][i];
    }
    cout << result%10007;
}