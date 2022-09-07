#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, num, sum=0; cin >> N;
    vector<int> A, B;
    for(int i=0; i<N; i++){
        cin >> num;
        A.push_back(num);
    }
    for(int i=0; i<N; i++){
        cin >> num;
        B.push_back(num);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    
    for(int i=0; i<N; i++) sum += A[i]*B[i];
    
    cout << sum;
}
