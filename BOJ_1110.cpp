#include <iostream>
#include <array>

using namespace std;

int func(int N){
    int cnt = 1;
    int temp;
    array<int, 2> arr;
    arr[0] = N/10; arr[1] = N%10;
    while(true){
        temp = arr[1]*10 + (arr[0]+arr[1])%10;
        if(temp==N) break;
        else{
            arr[0] = temp/10; arr[1] = temp%10;
            temp = arr[1]*10 + (arr[0]+arr[1])%10;
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int N; cin >> N;
    cout << func(N);
}
