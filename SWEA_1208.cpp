#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate(int T) {
    int result;
    int arr[100];
    for(int i=0; i<100; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<T; i++) {
        int min = min_element(arr, arr+100) - arr;
        int max = max_element(arr, arr+100) - arr;
        arr[min]++;
        arr[max]--;
    }

    result = *max_element(arr, arr+100) - *min_element(arr, arr+100);
    return result;
}

int main() {
    for(int i=0; i<10; i++) {
        int T;
        cin >> T;
        cout << "#" << i+1 << " " << calculate(T) << endl;
    }
}