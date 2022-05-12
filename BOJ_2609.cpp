#include <iostream>
using namespace std;

int GCD(int a, int b){
    if(b==0)return a;
    else return GCD(b,a%b);
}
int main(){
    int a, b;
    cin >> a;
    cin >> b;
    cout << GCD(a, b) << "\n";
    cout << a*b/GCD(a, b);
}