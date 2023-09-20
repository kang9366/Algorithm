#include <iostream>

using namespace std;

int func(int A, int B){
	int gap = B-A;
	if(gap==1 || gap==0){
		return -1;
	}else if(gap%2==0){
		return gap/2;
	}else{
		return (gap-1)/2;
	}
}

int main(){
	int T;
	long long A, B;
	cin >> T;

	for(int i=0; i<T; i++){
		cin >> A >> B;
		cout << "#" << i+1 << " " << func(A, B) << endl;
	}
}