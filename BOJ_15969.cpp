#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, num; cin >> N;
    vector<int> vec;
    for(int i=0; i<N; i++){
        cin >> num;
        vec.push_back(num);
    }
    
    cout << *max_element(vec.begin(), vec.end()) - *min_element(vec.begin(), vec.end());
    
}

