#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int K, num, temp; cin >> K;
    vector<int> vec, gp;
    int max, min, gap;

    for(int i=0; i<K; i++){
        cin >> num;
        for(int j=0; j<num; j++){
            cin >> temp;
            vec.push_back(temp);
        }
        sort(vec.begin(), vec.end(), greater<int>());
        max = vec[0];
        min = vec[vec.size()-1];
        for(int i=0; i<vec.size()-1; i++) gp.push_back(vec[i]-vec[i+1]);
        gap = *max_element(gp.begin(), gp.end());
        cout << "Class " << i+1 << "\n";
        cout << "Max " << max << ", " << "Min " << min << ", " << "Largest gap " << gap << "\n";
        vector<int>().swap(vec);
        vector<int>().swap(gp);
    }
}
