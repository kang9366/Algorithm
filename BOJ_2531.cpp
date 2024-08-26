#include <iostream>
#include <deque>
#include <set>
#include <map>

using namespace std;

map<int, int> m;
int c;

void add(int key) {
    if(m.find(key) != m.end()) m[key]++;
    else m.insert({key, 1});
}

void erase(int key) {
    if(m[key] == 1) m.erase(key);
    else m[key]--;
}

int main() {
    int N, d, k;
    cin >> N >> d >> k >> c;
    deque<int> dq;

    int arr[N];
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    for(int i = 0; i < k; i++) {
        dq.push_back(arr[i]);
        add(arr[i]);
    }

    int answer = 0;
    
    for(int i = k; i < N+k; i++) {
        int index = i;
        if(index >= N) index = i-N;

        erase(dq[0]);
        dq.pop_front();
        dq.push_back(arr[index]);
        add(arr[index]);
        
        add(c);
        if(m.size() > answer) answer = m.size();
        erase(c);
    }

    cout << answer;
}