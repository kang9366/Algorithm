#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    ll distance[N-1];
    ll price[N];
    ll answer = 0;
    
    for(int i = 0; i < N-1; i++) cin >> distance[i];
    for(int i = 0; i < N; i++) cin >> price[i];
    
    for(int i = 0; i < N-1; i++) {
        if(price[i] >= price[i+1]) {
            answer += distance[i]*price[i];
        } else {
            int j = i+1;
            for(; j < N; j++) {
                answer += distance[j-1]*price[i];
                if(price[i] > price[j]) break;
            }
            i = j-1;
        }
    }
    cout << answer;
}
