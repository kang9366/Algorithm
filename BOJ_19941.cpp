#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    string str;
    cin >> str;

    char arr[N];
    queue<int> q;
    for(int i = 0; i < N; i++) {
        arr[i] = str[i];
        if(str[i] == 'P') q.push(i);
    }

    int size = q.size();
    int answer = 0;
    for(int i = 0; i < size; i++) {
        int temp = q.front();
        int index = -1;
        for(int j = temp-K; j < temp; j++) {
            if(j < 0) continue;
            if(arr[j] == 'H') {
                answer++;
                index = j;
                break;
            }
        }

        for(int j = temp+1; j <= temp+K; j++) {
            if(index != -1) break;
            if(j > N) break;
            if(arr[j] == 'H') {
                answer++;
                index = j;
                break;
            }
        }

        if(index != -1) arr[index] = 'X';
        q.pop();
    }

    cout << answer;


}