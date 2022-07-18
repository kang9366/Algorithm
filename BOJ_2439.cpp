#include <iostream>

using namespace std;

int main(){
    int num; cin >> num;
    for(int i=0; i<num; i++){
        for(int j=num-1-i; j>0; j--) cout << " ";
        for(int j=0; j<i+1; j++) cout << "*";
        cout << "\n";
    }
}
