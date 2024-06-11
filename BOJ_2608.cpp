#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string str;
    stack<char> s;
    int answer = 0;
    int temp = 1;
    bool isValid = true;

    cin >> str;
    
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(') {
            s.push(str[i]);
            temp *= 2;
        } else if(str[i] == '[') {
            s.push(str[i]);
            temp *= 3;
        } else if(str[i] == ')') {
            if(s.empty() || s.top() != '(') {
                cout << 0;
                return 0;
            } else if(str[i-1] == '(') {
                answer += temp;
                temp /= 2;
                s.pop();
            } else {
                temp /= 2;
                s.pop();
            }
        } else if(str[i] == ']') {
            if(s.empty() || s.top() != '[') {
                cout << 0;
                return 0;
            } else if(str[i-1] == '[') {
                answer += temp;
                temp /= 3;
                s.pop();
            } else {
                temp /= 3;
                s.pop();
            }
        }
    }

    if(!s.empty()) cout << 0;
    else cout << answer;
}