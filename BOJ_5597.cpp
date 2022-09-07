#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int num;
    bool arr[30] = {false};
    vector<int> vec;
    for(int i=0; i<28; i++){
        cin >> num;
        arr[num-1] = true;
    }
    
    for(int i=0; i<30; i++){
        if(!arr[i]) vec.push_back(i+1);
    }
    sort(vec.begin(), vec.end());
    cout << vec[0] << "\n";
    cout << vec[1] << "\n";
}
