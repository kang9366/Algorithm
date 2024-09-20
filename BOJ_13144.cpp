#include <iostream>
#include <cstring>

#define MAX 100001

using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;

    int arr[N];
    bool visited[MAX];

    for(int i = 0; i < N; i++) cin >> arr[i];

    int en = 0;
    ll answer = 0;
    memset(visited, false, sizeof(visited));
    
    for(int st = 0; st < N; st++) {
        while(en < N) {
            if(visited[arr[en]]) break;
            visited[arr[en]] = 1;
            en++;
        }
        answer += en-st;
        visited[arr[st]] = 0;
    }
    cout << answer;
}