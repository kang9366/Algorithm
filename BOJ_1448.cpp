#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, temp;
    vector<int> vec;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> temp;
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end());

    for(int i=size(vec)-1; i>1; i--){
        if(vec[i]<vec[i-1]+vec[i-2]){
            cout << vec[i]+vec[i-1]+vec[i-2];
            return 0;
        }
    }
    cout << -1;
}