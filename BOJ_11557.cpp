#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int T; cin >> T;
    int temp, num;
    string college_name;
    
    for(int i=0; i<T; i++){
        cin >> temp;
        string S[temp]; int L[temp];
        for(int j=0; j<temp; j++){
            cin >> college_name >> num;
            S[j] = college_name; L[j] = num;
        }
        cout << S[max_element(L, L+temp) - L] << "\n";
    }
}


