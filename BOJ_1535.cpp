#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N;
	cin >> N;

	int cost[N], value[N], dp[101];

	for(int i=0; i<N; i++){
		cin >> cost[i];
		cin >> value[i];
	}

	for(int i=0; i<N; i++){
		for(int j=100; j>=cost[i]; j--){
			dp[j] = max(dp[j], dp[j-cost[i]]+value[i]);
		}
	}

	cout << dp[99];
}