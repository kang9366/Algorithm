#include <iostream>

using namespace std;

int GCD(int a, int b){
    int c;
    while (b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}


int main(){
    int x1, x2, y1, y2, x, y;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    
    y = y1*y2;
    x = x1*y2 + x2*y1;
    
    int gcd = GCD(x, y);
    
    cout << x/gcd << " " << y/gcd;
}
