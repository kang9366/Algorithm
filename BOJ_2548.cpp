#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int N, num; cin >> N;
    vector<int> vec;
    for(int i=0; i<N; i++){
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    int sum = 0;
    vector<int> result;
    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<vec.size(); j++){
            sum += abs(vec[i]-vec[j]);
        }
        result.push_back(sum);
        sum = 0;
    }
    cout << vec[min_element(result.begin(), result.end()) - result.begin()];
}
