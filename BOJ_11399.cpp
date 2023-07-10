#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int main(){
    int N, temp;
    vector<int> vec;
    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> temp;
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end(), less<int>());
    for(int i=1; i<N+1; i++) {
        vec[i] = vec[i] + vec[i-1];
    }

    cout << accumulate(vec.begin(), vec.end(), 0);
}