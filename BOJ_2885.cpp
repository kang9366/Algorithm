#include <iostream>

#define MAX 200

using namespace std;

int main() {
    int K, size = 1, cnt = 0;
    cin >> K;

    while(size < K) {
        size *= 2;
    }

    if(K == size) {
        cout << size << " " << 0;
        return 0;
    }

    int temp = 0;
    int answer_size = size;

    while(true) {
        cnt++;
        if(temp + size/2 < K) {
            temp += size/2;
            size /= 2;
        } else if(temp + size/2 > K) {
            size /= 2;
        } else {
            break;
        }
    }

    cout << answer_size << " " << cnt;
}