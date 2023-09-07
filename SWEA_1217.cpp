#include <iostream>

using namespace std;

int result = 1;

int pow(int N, int M){
	if(M==0){
		return 1;
	}else{
		return N*pow(N, M-1);
	}
}

int main(){
	int T, N, M;
	for(int i=1; i<=10; i++){
		cin >> T >> N >> M;
		cout << "#" << i << " " << pow(N, M) << endl;
	}
}