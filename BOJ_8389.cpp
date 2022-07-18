#include <iostream>

using namespace std;

int add(int num){
    if(num==1) return 1;
    else return num + add(num-1);
}

int main(){
    int num; cin >> num; cout << add(num);
}
