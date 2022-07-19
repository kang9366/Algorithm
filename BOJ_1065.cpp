#include <iostream>
#include <vector>
using namespace std;

int func(int N){
    int cnt, a, b, c;
    vector<int> vec;
    if(N < 100){
        cnt = N;
    }else{
        cnt = 99;
        for(int i=100; i<=N; i++){
            a = i/100; b = (i-a*100)/10; c = i-a*100-b*10;
            if((a-b)==(b-c)) cnt++;
        }
    }
    return cnt;
}

int main(){
    int N; cin >> N;
    cout << func(N);
}
