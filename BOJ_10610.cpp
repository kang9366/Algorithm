#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str; cin >> str;
    sort(str.begin(), str.end(), greater<>());
    if(str[str.size()-1]!='0'){
        cout << -1;
    }else{
        int sum = 0;
        for(auto o : str){
            sum += o-'0';
        }
        if(sum%3==0)
            cout << str;
        else
            cout << -1;
    }
}
