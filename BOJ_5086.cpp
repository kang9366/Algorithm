#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<string> vec;
    while(true){
        int a, b; cin >> a >> b;
        if(a==0&&b==0) break;
        else if(a%b==0) vec.push_back("multiple");
        else if(b%a==0) vec.push_back("factor");
        else vec.push_back("neither");
    }
    for (auto iter = vec.begin(); iter < vec.end() ; iter++ ) cout << *iter << endl;
}
