#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, k, score;
    vector<int> vec;
    cin >> N >> k;
    for(int i=0; i<N; i++){
        cin >> score;
        vec.push_back(score);
    }
    sort(vec.begin(), vec.end(), greater<int>());
    cout << vec[k-1];
}
