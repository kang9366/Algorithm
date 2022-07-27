#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, num, cnt=0; cin >> N;
    vector<int> vec;
    for(int i=0; i<N; i++){
        cin >> num;
        if(num==1){
            cnt++;
        }else{
            for(int j=2; j<num; j++) if(num%j==0) cnt++;
        }
    }
    cout << N-cnt;
}
