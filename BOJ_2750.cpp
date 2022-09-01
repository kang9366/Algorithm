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
    for(int i=0; i<vec.size(); i++) cout << vec[i] << "\n";
}
