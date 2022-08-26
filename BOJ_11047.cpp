#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vec;
    int N, K, value, n=0;
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> value;
        if(value<=K) vec.push_back(value);
        else continue;
    }
    
    for(int i=vec.size()-1; i>=0; i--){
        if(K==0) break;
        n += K/vec[i];
        K -= (K/vec[i])*vec[i];
    }
    cout << n;
}
