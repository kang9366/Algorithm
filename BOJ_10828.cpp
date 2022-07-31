#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, num; cin >> N;
    string str;
    stack<int> stk;
    for(int i=0; i<N; i++){
        cin >> str;
        if(str=="push"){
            cin >> num;
            stk.push(num);
        }else if(str=="pop"){
            if(stk.size()==0) cout << -1 << endl;
            else stk.pop();
        }else if(str=="size"){
            cout << stk.size() << endl;
        }else if(str=="empty"){
            cout << stk.empty() << endl;
        }else if(str=="top"){
            if(stk.size()==0) cout << -1 << endl;
            else cout << stk.top() << endl;
        }
    }
}
