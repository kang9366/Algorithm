#include <iostream>
#include <vector>

using namespace std;

void primeNum(int N, int M){
    vector<int> vec;
    vec.push_back(0); vec.push_back(0);
    for(int i=2; i<=M; i++) vec.push_back(i);
    for(int i=2; i<=M; i++){
        if(vec[i]==0) continue;
        for(int j=2*i; j<=M; j+=i) vec[j]=0;
    }
    for(int i=N; i<=M; i++) if(vec[i]!=0) cout << i << "\n";
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    primeNum(N, M);
}
