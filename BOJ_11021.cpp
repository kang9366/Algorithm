#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num, a, b; cin >> num;
    int cnt=0;
    vector<int> vec;
    while(true){
        cin >> a >> b;
        vec.push_back(a+b);
        cnt++;
        if(cnt==num){
            for(int i=0; i<num; i++) cout << "Case #" << i+1 << ": " << vec[i] << "\n";
            break;
        }
    }
}
