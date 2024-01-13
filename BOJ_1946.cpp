#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<pair<int, int>> vec) {
    int ans = 1;

    sort(vec.begin(), vec.end());

    int minSecond = vec[0].second;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i].second < minSecond) {
            ans++;
            minSecond = vec[i].second;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, a, b;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        vector<pair<int, int>> vec;
        for (int j = 0; j < N; j++) {
            cin >> a >> b;
            vec.push_back({a, b});
        }
        cout << solution(vec) << "\n";
    }

    return 0;
}
