#include <iostream>

using namespace std;

int findMaxValue(int a, int b, int arr[]) {
    int max = 0;
    for(int i = 0; i < 6; i++) {
        if(i == a || i == b) continue;
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

int findIndex(int value, int arr[]) {
    for(int i = 0; i < 6; i++) {
        if(arr[i] == value) return i;
    }
}

int main() {
    int N;
    cin >> N;

    int arr[N][6];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 6; j++) cin >> arr[i][j];
    }

    int temp[6] = { 5, 3, 4, 1, 2, 0 };

    int answer = 0;
    for(int i = 0; i < 6; i++) {
        int tmp = 0;
        int top = arr[0][temp[i]];
        tmp += findMaxValue(i, temp[i], arr[0]);

        for(int j = 1; j < N; j++) {
            int b = findIndex(top, arr[j]);
            int t = temp[b];
            tmp += findMaxValue(b, t, arr[j]);
            top = arr[j][t];
        }
        if(tmp > answer) answer = tmp;
    }
    cout << answer;
}