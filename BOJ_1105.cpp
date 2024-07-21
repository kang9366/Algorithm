#include <iostream>
#include <string>

using namespace std;

int main() {
    string L, R;
    cin >> L >> R;

    int answer = 0;

    if(L.length() != R.length()) {
        cout << answer;
        return 0;
    }

    for(int i = 0; i < L.length(); i++) {
        if(L[i] == '8' && R[i] == '8') {
            answer++;
        } else if(L[i] != R[i]) {
            break;
        }
    }
    
    cout << answer;
}