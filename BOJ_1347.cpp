#include <iostream>
#include <string>
#include <vector>

#define MAX 101

using namespace std;

char map[MAX][MAX];

int main() {
    int N;
    string str;

    cin >> N;
    cin >> str;

    int direction = 0;

    int x = 50, y = 50;

    vector<pair<int, int>> vec;
    int min_width = 50;
    int min_height = 50;
    int max_width = 50;
    int max_height = 50;

    vec.push_back({50, 50});
    map[50][50] = '.';

    for(int i = 0; i < N; i++) {
        if(str[i] == 'R') {
            if(direction == 3) direction = 0;
            else direction++;
        } else if(str[i] == 'L') {
            if(direction == 0) direction = 3;
            else direction--;
        } else {
            if(direction == 0) vec.push_back({++x, y});
            else if(direction == 1) vec.push_back({x, --y});
            else if(direction == 2) vec.push_back({--x, y});
            else vec.push_back({x, ++y});
            min_height = min(x, min_height);
            max_height = max(x, max_height);
            min_width = min(y, min_width);
            max_width = max(y, max_width);
            map[x][y] = '.';
        }
    }

    int width = max_width - min_width + 1;
    int height = max_height - min_height + 1;

    for(int i = min_height; i <= max_height; i++) {
        for(int j = min_width; j <= max_width; j++) {
            if(map[i][j] != '.') cout << '#';
            else cout << map[i][j];
        }
        cout << endl;
    }
}