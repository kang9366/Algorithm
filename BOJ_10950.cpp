#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num; cin >> num;
    int a, b;
    vector<int> vec;
    int cnt=0;
    while(true){
        cin >> a >> b;
        vec.push_back(a+b);
        cnt++;
        if(cnt==num){
            for(int i=0; i<num; i++) cout << vec[i] << endl;
            break;
        }
    }
}
