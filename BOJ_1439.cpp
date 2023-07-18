#include <iostream>

using namespace std;

int main(){
    string s;
    int cnt=0;

    cin >> s;


    for(int i=0; i<size(s)-1; i++){
        if(s[i]!=s[i+1]){
            cnt++;
        }
    }

    cout << (cnt+1)/2;
}