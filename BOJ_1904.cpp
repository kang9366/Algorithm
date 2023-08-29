#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> dp;
    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(2);
    for(int i=3; i<=N; i++){
        dp.push_back((dp[i-1] + dp[i-2])%15746);
    }

    cout << dp[N];
}