#include <iostream>
#include <string>

using namespace std;

int main(){
	int A, B;
	cin >> A >> B;
	int cnt=0;

	while(B>A){
		string str = to_string(B);
		if(str[str.size()-1]=='1'){
			B = stoi(str.substr(0, str.size()-1));
		}else if(B%2!=0){
			cout << -1;
			return 0;
		}else{
			B /= 2;
		}
		cnt++;
		if(A==B){
			cout << cnt+1;
			return 0;
		}
	}
	cout << -1;
}