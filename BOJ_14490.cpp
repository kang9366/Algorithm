#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b){
    return (a % b == 0 ? b : gcd(b, a % b));
}

int main(){
    string str; cin >> str;
    int index = (int) str.find(':');
    int n = stoi(str.substr(0,index));
    int m = stoi(str.substr(index+1));
    
    int num = gcd(n,m);
    cout << n/num << ":" << m/num;
}
