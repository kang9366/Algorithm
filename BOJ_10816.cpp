#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, temp;
    unordered_map<int, int> counts;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        counts[temp]++;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        cout << counts[temp] << " ";
    }
    return 0;
}