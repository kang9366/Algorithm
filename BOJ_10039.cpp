#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int arr[5];
    int sum = 0;
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        cin >> arr[i];
        if(arr[i]%5!=0) exit(0);
        if(arr[i]<40) arr[i] = 40;
        sum += arr[i];
    }
    cout << sum/5;
}
