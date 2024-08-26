#include <iostream>
#include <map>

#define SIZE 5

using namespace std;

typedef pair<int, int> coordinate;

map<int, coordinate> m;
bool check[SIZE][SIZE];
int cnt = 0;

void diagonal1() {
    bool flag = true;
    for(int i = 0; i < SIZE; i++) {
        if(!check[i][SIZE-i-1]) {
            flag = false;
            break;
        }
    }
    if(flag) cnt++;
}

void diagonal2() {
    bool flag = true;
    for(int i = 0; i < SIZE; i++) {
        if(!check[i][i]) {
            flag = false;
            break;
        }
    }
    if(flag) cnt++;
}

void col() {
    for(int i = 0; i < SIZE; i++) {
        bool flag = true;
        for(int j = 0; j < SIZE; j++) {
            if(!check[j][i]) {
                flag = false;
                break;
            }
        }
        if(flag) cnt++;
    }
}

void row() {
    for(int i = 0; i < SIZE; i++) {
        bool flag = true;
        for(int j = 0; j < SIZE; j++) {
            if(!check[i][j]) {
                flag = false;
                break;
            }
        }
        if(flag) cnt++;
    }
}

int main() {
    int num;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cin >> num;
            m.insert({num, {i, j}});
        }
    }

    int answer = 0;
    bool flag = false;

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cin >> num;
            if(flag) continue;
            answer++;
            coordinate cur = m[num];
            check[cur.first][cur.second] = true;
            cnt = 0;

            row();
            col();
            diagonal1();
            diagonal2();

            if(cnt>=3) flag = true;
        }
    }
    cout << answer;
}