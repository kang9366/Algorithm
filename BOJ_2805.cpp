#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long N, M;
    cin >> N >> M;

    long arr[N];

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long start = 0;
    long end = *max_element(arr, arr+N);

    while(true) {
        if(start == end) break;
        long sum = 0;
        long mid = (start + end) / 2;

        for(int i = 0; i < N; i++) {
            if(arr[i] - mid > 0) sum += (arr[i] - mid);
        }

        if(sum >= M) {
            start = mid+1;
        } else {
            end = mid;
        }
    }

    cout << start-1;
}
