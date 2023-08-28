#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i=0; i<N; i++){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    if(N%2!=0){
        cout << vec[N/2];
    }else{
        if(vec[N/2]<vec[(N/2)-1]){
            cout << vec[N/2];
        }else{
            cout << vec[(N/2)-1];
        }
    }
}