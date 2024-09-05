#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr+N);

    int left = 0;
    int right = N-1;
    int sum = 0;
    int temp = INT_MAX;
    pair<int, int> answer;

    while(left < right && right < N) {
        sum = arr[left] + arr[right];

        if(abs(sum) < temp) {
            temp = abs(sum);
            answer = { arr[left], arr[right] };
        }
        
        if(sum > 0) right--;
        else left++;
    }
    cout << answer.first << " " << answer.second;
}