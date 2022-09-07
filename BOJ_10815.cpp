#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, num; cin >> N;
    vector<int> vec;
    for(int i=0; i<N; i++){
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> num;
        cout << binary_search(vec.begin(), vec.end(), num) << "\n";
    }
}