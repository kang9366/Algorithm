#include<iostream>
using namespace std;

int main(){
    int N = 0;
    cin >> N;
    for(int i = 0; i < 9; i++){
        cout << N << " * " << (i+1) << " = " << N*(i+1) << "\n";
    }
}