#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, K;

    cin >> N >> K;
    
    long arr[N];

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long start = 0;
    long end = *max_element(arr, arr+N);

    while(start <= end) {
        long mid = (start + end) / 2;
        int cnt = 0;

        if(mid == 0) {
            break;
        }
        
        for(int i = 0; i < N; i++) {
            cnt += arr[i]/mid;
        }

        if(cnt >= K) {
            start = mid + 1;
        } else {
            end = mid-1;
        }
    }

    cout << end;
}