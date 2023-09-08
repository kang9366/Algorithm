#include <iostream>

using namespace std;

int func(int N){
	int result = 0;
	for(int i=-N; i<=N; i++){
		for(int j=-N; j<=N; j++){
			if(i*i+j*j<=N*N) result++;
		}
	}
	return result;
}

int main(){
	int T, N;
	cin >> T;

	for(int i=0; i<T; i++){
		cin >> N;
		cout << "#" << i+1 << " " << func(N) << endl;
	}
}