#include <iostream>
#include <deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, K, M;
    cin >> N >> K >> M;
    deque<int> dq;
    
    for(int i=0; i<N; i++){
        dq.push_back(i+1);
    }
    
    int cnt = 0;
    bool check = true;
    while(!dq.empty()){
        if(check){
            for(int i=0; i<K-1; i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
            cout << dq.front() << "\n";
            dq.pop_front();
        }else{
            for(int i=0; i<K-1; i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cout << dq.back() << "\n";
            dq.pop_back();
        }
        cnt++;
        if(cnt==M){
            check = false;
            cnt = 0;
        }
    }
}
