#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    long long temp;
    vector<long long> vec;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> temp;
        vec.push_back(temp);
    }


    while(m!=0){
        sort(vec.begin(), vec.end());
        temp = vec[0] + vec[1];
        vec[0] = temp;
        vec[1] = temp;
        m--;
    }

    cout << accumulate(vec.begin(), vec.end(), (long long) 0);
}