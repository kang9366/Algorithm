#include <iostream>
#define MAX(a, b) a > b ? a : b
using namespace std;

int main(){
    int a, b, c;
    cin >> a; cin >> b; cin>> c;
    if(a==b && a==c){
        cout << 10000 + a*1000;
    }else if(a==b || a==c){
        cout << 1000 + a*100;
    }else if(b==c){
        cout << 1000 + b*100;
    }else{
        cout << int(MAX(MAX(a,b), c))*100;
    }
}
