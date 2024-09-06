#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    int arr[N];
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr+N);
    
    int left = 0;
    int right = N-1;
    pair<int, int> answer;
    int temp = INT_MAX;
    
    while(left < right && right < N) {
        int sum = arr[left] + arr[right];
        
        if(abs(sum) < temp) {
            temp = abs(sum);
            answer = { arr[left], arr[right] };
        }
        
        if(sum < 0) left++;
        else if(sum > 0) right--;
        else {
            answer = { arr[left], arr[right] };
            break;
        }
    }
    
    cout << answer.first << " " << answer.second;
}