#include <iostream>
#include <string>

using namespace std;

int swap(int n){
    char temp;
    string str = to_string(n);
    temp = str[0];
    str[0] = str[2];
    str[2] = temp;
    return stoi(str);
}


int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b; cin >> a >> b;
    a = swap(a); b = swap(b);
    if(a>b) cout << a;
    else cout << b;
}
