#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, temp, sum=0; cin >> N >> M;
    vector<int> vec, result;
    for(int i=0; i<N; i++){
        cin >> temp;
        vec.push_back(temp);
    }
    
    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            for(int k=j+1; k<N; k++){
                sum = vec[i]+vec[j]+vec[k];
                if(sum<=M) result.push_back(sum);
                sum = 0;
            }
        }
    }
    sort(result.begin(), result.end());
    cout << result[result.size()-1];
}
