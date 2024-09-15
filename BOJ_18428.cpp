#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 6

using namespace std;

typedef pair<int, int> coordinate;

vector<coordinate> teacher;
vector<coordinate> temp;
vector<coordinate> student;

int N;
char map[MAX][MAX];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'T') teacher.push_back({i, j});
            else if(map[i][j] == 'X') temp.push_back({i, j});
            else if(map[i][j] == 'S') student.push_back({i, j});
        }
    }

    vector<bool> test(temp.size(), true);
    for(int i = 0; i < test.size()-3; i++) test[i] = false;

    coordinate arr[3];
    int index;
    do {
        index = 0;
        for(int i = 0; i < temp.size(); i++) {
            if(test[i]) {
                arr[index++] = { temp[i].first, temp[i].second };
                map[temp[i].first][temp[i].second] = 'O';
            }
        }
        
        bool flag = true;
        for(auto &i:teacher) {
            for(int j = i.first; j >= 0; j--) {
                if(map[j][i.second] == 'O') break;
                else if(map[j][i.second] == 'S') flag = false;
            }

            for(int j = i.first; j < N; j++) {
                if(map[j][i.second] == 'O') break;
                else if(map[j][i.second] == 'S') flag = false;
            }

            for(int j = i.second; j >= 0; j--) {
                if(map[i.first][j] == 'O') break;
                else if(map[i.first][j] == 'S') flag = false;
            }

            for(int j = i.second; j < N; j++) {
                if(map[i.first][j] == 'O') break;
                else if(map[i.first][j] == 'S') flag = false;
            }
        }

        if(flag) {
            cout << "YES";
            return 0;
        }

        for(int i = 0; i < 3; i++) map[arr[i].first][arr[i].second] = 'X';
    } while(next_permutation(test.begin(), test.end()));
    cout << "NO";
}