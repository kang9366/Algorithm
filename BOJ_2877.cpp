#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> vec;

    for(int i=0; i<N; i++) vec.push_back(i+1);

    cout << "<";
    int cnt=0;
    while(!vec.empty()){
        for(int i=0; i<vec.size(); ){
            cnt++;
            if(cnt == K){
                cout << vec[i];
                if(vec.size() != 1) cout << ", ";
                else cout << ">";
                vec.erase(vec.begin() + i);
                cnt = 0;
            } else {
                i++;
            }
        }
    }

}