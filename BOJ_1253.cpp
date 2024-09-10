#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];
    for(int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr+N);

    int answer = 0;
    for(int i = 0; i < N; i++) {
        vector<int> vec;
        for(int j = 0; j < N; j++) {
            if(j == i) continue;
            vec.push_back(arr[j]);
        }

        int left = 0;
        int right = vec.size()-1;

        while(left < right && right < vec.size()) {
            int sum = vec[left] + vec[right];

            if(sum == arr[i]) {
                answer++;
                break;
            } else if(sum > arr[i]) {
                right--;
            } else {
                left++;
            }
        }
    }
    cout << answer;
}