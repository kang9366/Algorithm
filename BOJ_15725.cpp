#include <iostream>
#include <string>

using namespace std;

int main(){
    string str; cin >> str;
    if(str.find('x')==string::npos){
        cout << 0;
    }else{
        if(str.substr(0,str.find('x'))==""){
            cout << 1;
        }else if(str.substr(0,str.find('x'))=="-"){
            cout << -1;
        }else{
            cout << str.substr(0,str.find('x'));
        }
    }
}
