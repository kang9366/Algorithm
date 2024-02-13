#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, B;
    pair<int, int> answer;
    cin >> N >> M >> B;

    int arr[N][M];
    int min = 0, max = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if(i == 0 && j == 0) {
                min = arr[i][j];
                max = arr[i][j];
            } else {
                min = std::min(min, arr[i][j]);
                max = std::max(max, arr[i][j]);
            }
        }
    }

    for(int i = min; i <= max; i++) {
        int cnt = B, time = 0;
        
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(arr[j][k] > i) {
                    time += 2 * (arr[j][k] - i);
                    cnt += arr[j][k] - i;
                } else if(arr[j][k] < i) {
                    time += i - arr[j][k];
                    cnt -= i - arr[j][k];
                }
            }
        }

        if(i == min) {
            answer.first = time;
            answer.second = i;
        }

        if(cnt >= 0) {
            if(time == answer.first) {
                answer.first = time;
                answer.second = std::max(answer.second, i);
            }else if(time < answer.first){
                answer.first = time;
                answer.second = i;
            }
        }
    }

    cout << answer.first << " " << answer.second;
}
