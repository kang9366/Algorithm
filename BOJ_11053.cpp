#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int arr[N], dp[N];

    for(int i=0; i<N; i++){
        cin >> arr[i];
        dp[i] = 1;
    }

    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    cout << *max_element(dp, dp+N);
}