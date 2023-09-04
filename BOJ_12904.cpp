#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string S, T;
    cin >> S >> T;

    while(T.size()!=S.size()){
        if(T[T.size()-1]=='A'){
            T.erase(T.size()-1);
        }else{
            T.erase(T.size()-1);
            reverse(T.begin(), T.end());
        }
    }
    if(T==S){
        cout << 1;
    }else{
        cout << 0;
    }
}