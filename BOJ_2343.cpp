#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, M;

    cin >> N >> M;

    int arr[N];
    int start, end = 0;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        end += arr[i];
    }

    start = *max_element(arr, arr+ N);

    while(start <= end) {
        int mid = (start+end)/2;
        int sum = 0;
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if (sum + arr[i] > mid) {
				sum = 0;
				cnt++;
			}
			sum += arr[i];
        }
        if (sum != 0) cnt++;

        if(cnt > M) {
            start = mid+1;
        } else {
            end = mid-1;
        }
    }
    cout << end+1;
}