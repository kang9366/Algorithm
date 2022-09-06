#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N, M, num, x, y; cin >> N >> M;
    vector<int> vec;
    
    for(int i=0; i<N; i++){
        cin >> num;
        if(i==0) vec.push_back(num);
        else vec.push_back(num+vec[i-1]);
    }
    
    for(int i=0; i<M; i++){
        cin >> x >> y;
        if(x==1){
            cout << vec[y-1] << "\n";
        }else{
            cout << vec[y-1]-vec[x-2] << "\n";
        }
    }
}
