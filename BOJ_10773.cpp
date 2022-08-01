#include <iostream>
#include <string>
#include <stack>
#include <numeric>

using namespace std;

int main(){
    int K, temp, sum=0; cin >> K;
    stack<int> st;
    for(int i=0; i<K; i++){
        cin >> temp;
        if(temp==0 && st.size()!=0) st.pop();
        else st.push(temp);
    }
    
    temp = st.size();
    for(int i=0; i<temp; i++){
        sum += st.top();
        if(st.size()!=0) st.pop();
        else break;
    }
    cout << sum;
}
