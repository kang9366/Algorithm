#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N, M;
	cin >> N;
	int arr[N];
	for(int i=0; i<N; i++){
		cin >> arr[i];
	}
	cin >> M;

	sort(arr, arr+N);
	int min=1, max=arr[N-1], mid, cnt, result;

	while(min<=max){
		cnt = 0;
		mid = (min+max)/2;

		for(auto i=0; i<N; i++) {
			if(arr[i]>=mid){
				cnt += mid;
			}else{
				cnt += arr[i];
			}
		}
		if(M>=cnt){
			result = mid;
			min = mid+1;
		}else{
			max = mid-1;
		}
	}
	cout << result;
}