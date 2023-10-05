#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


int findMode(vector<int> vec){
	map<int, int> freqMap;
    int maxCount = 0;
    int mode = -1;
    
    for (int num : vec) {
        freqMap[num]++;
    }
    
    for (const auto& pair : freqMap) {
        if (pair.second >= maxCount) {
            maxCount = pair.second;
            mode = pair.first;
        }
    }

    return mode;
}

int main(){
    int T, N;
    cin >> T;
    
    for(int i=0; i<T; i++){
        vector<int> vec(100);
		cin >> N;
        for(int i=0; i<100; i++){
    		cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        cout << "#" << i+1 << " " << findMode(vec) << endl;
    }
}