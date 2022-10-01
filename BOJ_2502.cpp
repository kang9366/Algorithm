#include <iostream>
#include <vector>

using namespace std;

pair<int, int> func(int A, int B, int K);
int fibo(int A, int B, int D);

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int D, K; cin >> D >> K;
    pair<int, int> result;
    if(D==3)
        result = func(1, 1, K);
    else if(D==4)
        result = func(1, 2, K);
    else
        result = func(fibo(1, 1, D-2), fibo(1, 2, D-2), K);
    
    cout << result.first << endl << result.second;
}

pair<int, int> func(int intercept_A, int intercept_B, int K){
    int A=1;
    int B;
    pair<int, int> result;
    while(true){
        if((K-intercept_A*A)%intercept_B==0){
            B = (K-intercept_A*A)/intercept_B;
            result.first = A;
            result.second = B;
            break;
        }else{
            A++;
        }
    }
    return result;
}

int fibo(int A, int B, int D){
    int dp[D];
    dp[0] = A;
    dp[1] = B;
    if(D <= 2){
        return dp[D];
    }else{
        for(int i = 2; i <= D; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[D-1];
    }
}