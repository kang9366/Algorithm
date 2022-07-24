#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<long long> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    for(int i = 6; i <= 1000; i++) vec.push_back(vec[i-1] + vec[i-5]);
    
    int num;
    vector<int> vec2;
    cin >> num;
    for(int i = 0; i < num; i++){
        int temp;
        cin >> temp;
        vec2.push_back(temp);
    }
    
    for (int i=0; i<num; i++) cout << vec[vec2[i]] << endl;
}
