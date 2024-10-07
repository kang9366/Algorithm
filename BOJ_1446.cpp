#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    int dp[D+1];
    memset(dp, 0, sizeof(dp));
    vector<pair<pair<int, int>, int>> vec;

    pair<pair<int, int>, int> arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
    }

    for(int i = 1; i <= D; i++) {
        dp[i] = dp[i-1] + 1;
        for(int j = 0; j < N; j++) {
            if(i == arr[j].first.second) {
                dp[i] = min(dp[i], dp[arr[j].first.first] + arr[j].second);
            }
        }
    }

    cout << dp[D];
}