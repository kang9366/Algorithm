#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int a, b, c;
    vector<int> vec;
    while(true){
        cin >> a >> b >> c;
        if(a==b && a==c && a==0) break;
        vec.push_back(a); vec.push_back(b); vec.push_back(c);
        sort(vec.begin(), vec.end());
        if(vec[2]*vec[2]==vec[1]*vec[1]+vec[0]*vec[0]) cout << "right";
        else cout << "wrong";
        vector<int>().swap(vec);
    }
}

