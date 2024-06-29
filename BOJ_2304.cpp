#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10000];

int main() {
    int N, L, H, answer = 0;
    vector<pair<int, int>> vec;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> L >> H;
        vec.push_back({L, H});
        arr[L] = H;
    }

    sort(vec.begin(), vec.end());

    int start = vec[0].first, end = vec[vec.size()-1].first;

    int value = 0, index = 0;

    for(auto &i : vec) {
        if(i.second > value) {
            value = i.second;
            index = i.first;
        }
    }

    answer += value;

    int idx = index;

    while(idx < end) {
        int max = *max_element(arr+idx+1, arr+end+1);
        int max_index = max_element(arr+idx+1, arr+end+1) - arr;

        answer += (max_index - idx) * max;
        idx = max_index;
    }

    idx = index;

    while(idx > start) {
        int max = *max_element(arr, arr+idx);
        int max_index = max_element(arr, arr+idx) - arr;
        answer += (idx - max_index) * max;
        idx = max_index;
    }
    cout << answer;
}