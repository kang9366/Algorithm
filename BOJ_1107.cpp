#include <iostream>
#include <string>
#include <climits>

#define MAX 500000
#define DEFAULT 100

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    string str = to_string(N);

    bool arr[10] = { 0, };

    for(int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        arr[temp] = true;
    }

    int answer = abs(N-DEFAULT);

    for(int i = 0; i <= MAX*2; i++) {
        bool flag = true;
        string str2 = to_string(i);
        for(int j = 0; j < str2.size(); j++) {
            if(arr[str2[j] - '0'] == 1) {
                flag = false;
                break;
            }            
        }
        if(!flag) continue;
        int temp = abs(N-i) + str2.size();
        answer = min(temp, answer);
    }
    cout << answer;
}