#include <iostream>

using namespace std;

int arr[11];

int main() {
    int N, temp;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> temp;

        int cnt = 0;
        for(int j = 1; j <= N; j++) {
            if(arr[j] == 0 && cnt == temp) {
                arr[j] = i;
                break;
            }
            else if(arr[j] == 0) cnt++;
        }
    }

    for(int i = 1; i <= N; i++) {
        cout << arr[i] << " ";
    }
}