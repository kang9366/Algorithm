#include <iostream>
#include <vector>

using namespace std;


bool checkAscending(vector<int> vec){
    for(int i=1; i<=8; i++) if(i!=vec[i-1]) return false;
    return true;
}

bool checkDescending(vector<int> vec){
    int t=0;
    for(int i=8; i>=1; i--){
        if(i!=vec[t]) return false;
        t++;
    }
    return true;
}

int main(){
    vector<int> vec;
    int temp;
    for(int i=1; i<=8; i++){
        cin >> temp;
        vec.push_back(temp);
    }
    
    if(checkDescending(vec)) cout << "descending";
    else if(checkAscending(vec)) cout << "ascending";
    else cout << "mixed";
}
