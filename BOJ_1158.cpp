#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    queue<int> q;
    
    for(int i=0; i<N; i++){
        q.push(i+1);
    }
    
    vector<int> vec;
    while(!q.empty()){
        for(int i=0; i<K-1; i++){
            q.push(q.front());
            q.pop();
        }
        vec.push_back(q.front());
        q.pop();
    }
    cout << "<";
    for(int i=0; i<vec.size()-1; i++){
        cout << vec[i] << ", ";
    }
    cout << vec.back() << ">";
}
