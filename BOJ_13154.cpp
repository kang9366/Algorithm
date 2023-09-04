#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, K, result=0;
    cin >> N >> K;

    int arr[N], diff[N-1];
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);


    for(int i=0; i<N-1; i++){
        diff[i] = arr[i+1]-arr[i];
    }
    sort(diff, diff+N-1);

    for(int i=0; i<N-K; i++){
        result += diff[i];
    }

    cout << result;
}