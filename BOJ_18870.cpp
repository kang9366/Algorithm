#include <iostream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    set<int> s;
    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }

    map<int, int> m;
    int rank = 0;
    for(auto &i : s) m.insert({i, rank++});
    for(auto &i : arr) cout << m[i] << " ";
}