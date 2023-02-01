#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T, N, temp;
    cin >> T;
    vector<int> vec;
    vector<int> result;
    for(int i=0; i<T; i++){
        cin >> N;
        for(int j=0; j<N; j++){
            cin >> temp;
            vec.push_back(temp);
        }
        sort(vec.begin(), vec.end());
        for(int k=2; k<N; k++){
            temp = vec[k]-vec[k-2];
            result.push_back(temp);
        }
        cout << *max_element(result.begin(), result.end());
        vector<int>().swap(vec);
        vector<int>().swap(result);
    }
}
