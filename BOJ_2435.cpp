#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N, K, temp, result;
    vector<int> vec;

    cin >> N >> K;
    
    vector<int> vec_cumsum;
    vec_cumsum.push_back(0);
    
    for(int i=0; i<N; i++){
        cin >> temp;
        vec.push_back(temp);
        vec_cumsum.push_back(vec_cumsum[i] + vec[i]);
    }

    temp = vec_cumsum[K];
    for(int i=1; i<N-K+1; i++){
        result = vec_cumsum[i+K]-vec_cumsum[i];
        if(result > temp){
            temp = result;
        }
    }
    cout << temp;
}