#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int N; cin >> N;
    int sum = 0;
    string str; cin >> str;
    vector<int> vec;
    for(int i=0; i<N; i++){
        vec.push_back(str[i]-48);
        sum += vec[i];
    }
    cout << sum;
    
}
