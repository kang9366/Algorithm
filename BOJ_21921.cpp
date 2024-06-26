#include <iostream>

#define MAX 250000

using namespace std;

int main() {
    int N, X;
    int arr[MAX];

    cin >> N >> X;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    int s = 0, e = X-1;

    for(int i = s; i <= e; i++) {
        sum += arr[i];
    }

    int answer = sum, cnt;

    if(sum == 0) {
        cnt = 0;
    } else {
        cnt = 1;
    }


    while(true) {
        if(e == N-1) break;
        sum -= arr[s++];
        sum += arr[++e];
        if(sum == answer) {
            cnt++;
        } else if(sum > answer) {
            cnt = 1;
            answer = sum;
        }
    }

    if(answer == 0) {
        cout << "SAD";
    } else {
        cout << answer << "\n" << cnt;
    }
}