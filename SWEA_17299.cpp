#include <iostream>

using namespace std;

int func(int N){
	int A, B;
	string str = to_string(N);
	if(str.size()%2==0){
		A = stoi(str.substr(0, str.size()/2));
		B = stoi(str.substr(str.size()/2, str.size()-1));
		return A+B;
	}else{
		A = stoi(str.substr(0, str.size()/2))+stoi(str.substr(str.size()/2, str.size()-1));
		B = stoi(str.substr(0, str.size()/2+1))+stoi(str.substr(str.size()/2+1, str.size()-1));
		if(A>B){
			return B;
		}else{
			return A;
		}
	}
}

int main(){
	int T, N;
	cin >> T;

	for(int i=1; i<=T; i++){
		cin >> N;
		cout << "#" << i << " " << func(N) << endl;
	}
}