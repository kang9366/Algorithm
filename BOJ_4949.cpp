#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    while(true) {
        string str;
        getline(cin, str);
        if(str == ".") break;

        stack<char> s;
        bool isValid = true;

        for(auto c : str) {
            if(c == '(' || c == '[') s.push(c);
            else if(c == ']') {
                if(s.empty() || s.top() != '[') {
                    isValid = false;
                    break;
                }
                s.pop();
            } else if(c == ')') {
                if(s.empty() || s.top() != '(') {
                    isValid = false;
                    break;
                }
                s.pop();
            }
        }

        if(!s.empty()) isValid = false;
        if(isValid) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}