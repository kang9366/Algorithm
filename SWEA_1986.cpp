#include <iostream>
#include <vector>

using namespace std;

int func(int N){
    int result = 1;
    for(int i=2; i<=N; i++){
        if(i%2==0){
            result -= i;
        }else{
            result += i;
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