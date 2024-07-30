#include <iostream>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, S;
	cin >> N >> S;

	int* arr = new int[N];
	int answer = INT_MAX;

	for(int i = 0; i < N; i++) cin >> *(arr+i);
	int start = 0, end = 0, temp = 1, sum = *arr;

	while(start <= end && end < N) {
		if(sum < S) {
			sum += *(arr+(++end));
			temp++;
		} else {
			if(temp < answer) answer = temp;
			sum -= *(arr+(start++));
			temp--;
		}
	}

	if(answer == INT_MAX) cout << 0;
	else cout << answer;
}