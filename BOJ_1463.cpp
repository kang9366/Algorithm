#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000000];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	if(N==0 || N==1){
		cout << 0;
		return 0;
	}

	for(int i=2; i<=N; i++){
		dp[i] = dp[i-1] + 1;
		if(i%2==0){
			dp[i] = min(dp[i], dp[i/2]+1);
		}
		if(i%3==0){
			dp[i] = min(dp[i], dp[i/3]+1);
		}
	}
	cout << dp[N];
}