#include <iostream>

using namespace std;

int main(){
    unsigned long S, cnt=1, sum=0;;
    cin >> S;
    while(sum<S){
        sum += ++cnt;
    }
    cout << cnt-1;
}