#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> primeNum(int N, int M){
    vector<int> vec;
    vector<int> result;
    vec.push_back(0); vec.push_back(0);
    for(int i=2; i<=M; i++) vec.push_back(i);
    for(int i=2; i<=M; i++){
        if(vec[i]==0) continue;
        for(int j=2*i; j<=M; j+=i) vec[j]=0;
    }
    for(int i=N; i<=M; i++) if(vec[i]!=0) result.push_back(i);
    return result;
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> vec = primeNum(N, M);
    if(vec.size()==0){
        cout << -1;
    }else{
        cout << accumulate(vec.begin(), vec.end(), 0) << "\n";
        cout << vec[0];
    }
}
