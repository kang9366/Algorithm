#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N; cin >> N;
    string str = to_string(N);
    vector<int> vec;
    for(int i=0; i<str.size(); i++){
        vec.push_back(int(str[i]-'0'));
    }
    sort(vec.begin(), vec.end());

    for(int i=vec.size()-1; i>=0; i--) cout << vec[i];
}
