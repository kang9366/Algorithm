#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[N];

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int M, gender, num;
    cin >> M;

    for(int i = 0; i < M; i++) {
        int cnt = 1;
        cin >> gender >> num;

        if(gender == 1) {
            while(num*cnt <= N) {
                arr[num*cnt-1] = !arr[num*cnt-1];
                cnt++;
            }
        } else {
            arr[num-1] = !arr[num-1];
            for(int j = num; j < N; j++) {
                if(num-cnt-1 < 0 || arr[j] != arr[num-cnt-1]) break;
                arr[j] = !arr[j];
                arr[num-cnt-1] = !arr[num-cnt-1];
                cnt++;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
        if((i+1)%20 == 0) cout << endl;
    }
}