#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str; cin >> str;
    char c;
    int maxNum = 1;
    int cnt;
    bool b;
    for(int i=0; i<str.size(); i++){
        str[i] = toupper(str[i]);
    }
    
    for(int i=0; i<str.size()-1; i++){
        cnt = 1;
        if(str[i]=='0'){
            continue;
        }else{
            for(int j=i; j<str.size()-1; j++){
                if(str[i]==str[j+1]){
                    str[j+1] = '0';
                    cnt++;
                }
            }
        }
        if(cnt > maxNum){
            c = str[i];
            maxNum = cnt;
            b = true;
        }else if(cnt==maxNum){
            b = false;
        }
    }
    
    if(str.size()==1){
        cout << str;
    }else if(b){
        cout << c;
    }else{
        cout << "?";
    }
}
