#include <iostream>
#include <string>

using namespace std;

int main(){
    int T; cin >> T;
    string str;
    for(int i=0; i<T; i++){
        cin >> str;
        cout << str[0] << str[str.size()-1] << "\n";
    }
}