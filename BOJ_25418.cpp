#include <iostream>

using namespace std;

int main() {
    int A, K, cnt = 0;
    cin >> A >> K;

    while(A != K) {
        if(K < A) {
            cnt += K*2-A-1;
            break;
        }
        if(K%2 == 0) {
            K /= 2;
        } else {
            K--;
        }
        cnt++;
    }
    cout << cnt;
}