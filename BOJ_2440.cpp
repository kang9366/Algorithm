#include <iostream>

using namespace std;

int main(){
    int N; cin >> N;
    for(int i=N; i>0; i--){
        for(int j=i; j>0; j--){
            cout << "*";
        }
        cout << "\n";
    }
}
