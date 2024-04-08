#include <iostream>
#include <algorithm>

#define MAX 301

using namespace std;

int dp[MAX];
int arr[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = arr[3] + max(arr[1], arr[2]);

    for(int i = 4; i <= N; i++) {
        dp[i] = arr[i] + max({dp[i-3] + arr[i-1], dp[i-2]});
    }

    cout << dp[N];
}
