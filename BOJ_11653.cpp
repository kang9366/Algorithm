#include <iostream>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N; cin >> N;
    
    if(N==1) exit(0);
    
    for(int i=2; i<=N; i++){
        if(N==i){
            cout << i << "\n";
            break;
        }
        if(N%i==0){
            N /= i;
            cout << i << "\n";
            i--;
        }
    }
}
