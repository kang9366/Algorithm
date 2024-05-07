#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N, temp;
    priority_queue<int, vector<int>, greater<int>> p;
    priority_queue<int, vector<int>, greater<int>> m;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> temp;
        if(temp < 0) {
            m.push(-temp);
        } else if(temp > 0) {
            p.push(temp);
        } else if(temp == 0) {
            if(p.empty() && m.empty()) {
                cout << "0\n";
            } else if(!p.empty() && m.empty()) {
                cout << p.top() << "\n";
                p.pop();
            } else if(p.empty() && !m.empty()) {
                cout << -m.top() << "\n";
                m.pop();
            } else if(!p.empty() && !m.empty()) {
                if(p.top() >= m.top()) {
                    cout << -m.top() << "\n";
                    m.pop();
                } else if(p.top() < m.top()) {
                    cout << p.top() << "\n";
                    p.pop();
                }
            }
        }
    }
}