#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;

    cin >> N >> K;

    string temp;
    int cnt = 1;
    while(cnt <= N) {
        temp = to_string(cnt);
        if(temp.size() >= K) {
            cout << temp[K-1];
            return 0;
        }
        else K -= temp.size();
        cnt++;
    }
    cout << -1;
}