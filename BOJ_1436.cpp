#include <iostream>
#include <string>

using namespace std;

int main(){
    int i=666, cnt = 0;
    int N; cin >> N;
    while(true){
        if(to_string(i).find("666")!=string::npos) cnt++;
        if(cnt==N){
            cout << i;
            break;
        }else{
            i++;
        }
    }
}
