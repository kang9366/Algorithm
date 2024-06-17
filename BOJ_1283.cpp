#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

#define MAX 30

using namespace std;

vector<string> arr[MAX];
set<char> s;

void print(string str, int index) {
    if(index == -1) {
        cout << str;
    } else {
        for(int i = 0; i < str.size(); i++) {
            if(i == index) {
                cout << '[' << str[i] << ']';
            } else {
                cout << str[i];
            }
        }
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    for(int i = 0; i <= N; i++) {
        string str, sst;
        getline(cin, str);
        sst = str;

        istringstream iss (str);
        while(iss >> str) { arr[i].push_back(str); }

        bool temp = false;
        int index = -1;
        int tp = 0;
        for(int j = 0; j < arr[i].size(); j++) {
            if(s.count(toupper(arr[i][j][0])) == 0 && s.count(tolower(arr[i][j][0])) == 0) {
                s.insert(arr[i][j][0]);
                index = tp;
                temp = true;
                break;
            }
            tp += arr[i][j].size() + 1;
        }

        bool temp2 = false;

        if(!temp) {
            int tt = 0;
            for(int j = 0; j < arr[i].size(); j++) {
                for(int k = 0; k < arr[i][j].size(); k++) {
                    if(arr[i][j][k] == ' ') continue;
                    if(s.count(toupper(arr[i][j][k])) == 0 && s.count(tolower(arr[i][j][k])) == 0) {
                        s.insert(arr[i][j][k]);
                        index = tt;
                        temp2 = true;
                        break;
                    }
                    tt++;
                }
                if(temp2) break;
                tt++;
            }
        }
        if(i != 0) print(sst, index);
    }
}