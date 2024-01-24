#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    string arr[N];
    string answer[N];
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int cnt = 1;
    int k = arr[0].size();
    while(cnt != k) {
        set<string> s;
        for(int i = 0; i < N; i++) {
            string str = arr[i];
            answer[i] = str.substr(str.size() - cnt, str.size()-1);
            s.insert(answer[i]);
        }
        if(s.size() == N){
            cout << cnt;
            return 0;
        } else {
            cnt++;
        }
    }
    // cout << k;
}