#include <iostream>

#define MAX 200001

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    int arr[MAX];
    int cnt[MAX];
    int index[MAX];

    for(int i = 1; i <= N; i++) cin >> arr[i];

    int left = 1, right = 1;
    int answer = 0;
    
    while(left <= right && right <= N) {
        if(cnt[arr[right]] >= K) {
            cnt[arr[left]]--;
            left++;
        } else {
            cnt[arr[right]]++;
            right++;
        }
        answer = max(answer, right - left);
    }
    cout << answer;
}