#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, d, cnt=0; cin >> n >> d;
    string str;
    for(int i=1; i<=n; i++){
        str = to_string(i);
        for(int j=0; j<str.size(); j++){
            if((str[j]-'0')==d) cnt++;
        }
    }
    cout << cnt;
}
