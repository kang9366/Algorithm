#include <iostream>

using namespace std;

int main(){
    int T, A, B;
    cin >> T;
    for(int i=0; i<T; i++){
     	cin >> A >> B;
        if(A+B==24){
            cout << "#" << i+1 << " " << 0 << endl;
        }else if(A+B<24){
         	cout << "#" << i+1 << " " << A+B << endl;
        }else{
         	cout << "#" << i+1 << " " << A+B-24 << endl;
        }
    }
}