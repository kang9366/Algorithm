#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    cin >> str;

    list<char> l;
    list<char>::iterator iter = l.end();
    for(int i = 0; i < str.size(); i++) l.push_back(str[i]);
    
    int N;
    char M, ch;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> M;

        if(M == 'P') {
            cin >> ch;
            l.insert(iter, ch);
        } else if(M == 'B') {
            if(iter == l.end()) {
                l.erase(--iter);
                iter = l.end();
            }
            else if(iter != l.begin()) {
                iter = l.erase(--iter);
            }
        } else if(M == 'L') {
            if(iter != l.begin()) iter--;
        } else if(M == 'D') {
            if(iter != l.end()) iter++;
        }
    }
    
    for(iter = l.begin(); iter != l.end(); iter++) cout << *iter;
}