#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for(int i = 0; i < T; i++) {
		int N;
		cin >> N;
		int arr[N];
		int max = -1;
		int index = -1;

		for(int j = 0; j < N; j++) {
			cin >> arr[j];
			if(arr[j] > max) {
				max = arr[j];
				index = j;
			}
		}

		int start = 0;
		long long answer = 0;

		while(start < index && index < N) {
			for(int j = start; j < index; j++) {
				if(arr[j] < max) answer += max-arr[j];
				
			}

			if(index+1 >= N) break;
			start = index+1;
			index = max_element(arr+start+1, arr+N) - arr;
			max = *max_element(arr+start+1, arr+N);
		}
		cout << answer << '\n';
	}
}