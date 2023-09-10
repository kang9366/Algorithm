#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int T;
	cin >> T;

	int arr[T];

	for(int i=0; i<T; i++){
		cin >> arr[i];
	}
	sort(arr, arr+T);
	int result = 0;
	for(int i=0; i<T; i++){
		if(arr[i]*(T-i)>=result){
			result = arr[i]*(T-i);
		}
	}
	cout << result;
}