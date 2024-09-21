#include <iostream>
#include <map>

using namespace std;

map<int, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    int arr[N];
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = 1; i <= 9; i++) m.insert({i, 0});

    int left = 0;
    int right = 0;
    int answer = 0;

    while(left <= right && right < N) {
        int cnt = 0;
        m[arr[right]]++;

        for(int i = 1; i <= 9; i++) if(m[i] >= 1) cnt++;

        if(cnt > 2) {
            m[arr[right]]--;
            m[arr[left]]--;
            left++;
        } else {
            answer = max(answer, right-left+1);
            right++;
        }
    }
    cout << answer;
}