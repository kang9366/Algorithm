#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string str; cin >> str;
    int length = str.size();
    string arr[length];
    arr[0] = str;
    
    for(int i=1; i<length; i++){
        str = str.erase(0, 1);
        arr[i] = str;
    }
    sort(arr, arr+length);
    for(int i=0; i<length; i++){
        cout << arr[i] << endl;
    }
}
