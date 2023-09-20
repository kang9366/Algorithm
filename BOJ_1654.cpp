#include <iostream>

using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, result = 0;
	long long min=1, max=0, mid, cnt;

	cin >> N >> K;
	int arr[N];
	

	for(int i=0; i<N; i++){
		cin >> arr[i];
		if(max<arr[i]) max = arr[i];
	}

	while(min<=max){
		mid = (min+max)/2;
		cnt = 0;

		for(int i=0; i<N; i++){
			cnt += arr[i]/mid;
		}
		if(cnt>=K){
			min = mid+1;
			if(result<mid) result = mid;
		}else{
			max = mid-1;
		}
	}
	cout << result;
}