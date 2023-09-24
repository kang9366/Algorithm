#include <iostream>
#include <string>

using namespace std;

int main(){
 	int N, cnt;
    string str;
    cin >> N;
    for(int i=0; i<N; i++){
        cnt = 0;
        cin >> str;
        for(int j=0; j<str.size(); j++){
         	if(str[j]=='o') cnt++;
        }
        if(15-str.size()+cnt>=8) cout << "#" << i+1 << " YES" << endl;
        else cout << "#" << i+1 << " NO" << endl;
    }
}