#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    pair<int, int> arr[N];
    vector<int> answer;

    for(int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(int j = 0; j < N; j++) {
            if(arr[i] == arr[j]) continue;
            if(arr[i].second < arr[j].second && arr[i].first < arr[j].first) {
                cnt++;
            }
        }
        answer.push_back(cnt+1);
    }

    for(auto &i : answer) {
        cout << i << " ";
    }
}