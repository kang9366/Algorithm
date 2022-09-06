#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(){
    int N, M; cin >> N >> M;
    int n = sqrt(N);
    vector<int> vec;
    while(true){
        if(pow(n,2)>M) break;
        if(pow(n, 2)>=N) vec.push_back(n*n);
        n++;
    }
    
    if(vec.size()==0) cout << -1;
    else{
        cout << accumulate(vec.begin(), vec.end(), 0) << endl;
        cout << *min_element(vec.begin(), vec.end());
    }
}
