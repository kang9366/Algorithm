#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K, w, v;
    vector<int> weight, value;
    int dp[101][100001];

    cin >> N >> K;
    weight.push_back(0);
    value.push_back(0);

    for(int i = 0; i < N; i++) {
        cin >> w >> v;
        weight.push_back(w);
        value.push_back(v);
    }

    for(int  i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            if(weight[i] <= j) dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+ value[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[N][K];
    return 0;
}