#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int arr[N+1];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);

    int start = 0, end = 1;
    int answer = INT_MAX;

    while(start < N) {
        int temp = arr[end] - arr[start];
        if(temp < M) end++;
        else if(temp == M) {
            cout << M;
            return 0;
        } else {
            answer = min(answer, temp);
            start++;
        }
    }

    cout << answer;
}