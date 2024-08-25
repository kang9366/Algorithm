#include <iostream>
#include <map>
#include <deque>

#define APPLE 2
#define SNAKE 3
#define MAX 101

using namespace std;

typedef pair<int, int> coordinate;

int answer = 0;
int N, K, L;
int board[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int x, y;

char direction = 'D';

map<int, char> m;
deque<coordinate> snake;
int cur = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    cin >> K;
    
    for(int i = 0; i < K; i++) {
        cin >> x >> y;
        board[x][y] = APPLE;
    }
    board[1][1] = SNAKE;
    
    snake.push_front({1, 1});
    coordinate tail = snake.front();

    cin >> L;
    for(int i = 0; i < L; i++) {
        int X;
        char C;
        cin >> X >> C;
        m.insert({X, C});
    }

    x = 1, y = 1;
    bool flag = false;
    while(true) {
        answer++;

        if(flag) {
            if(direction == 'D') {
                if(cur == 0) cur = 2;
                else if(cur == 1) cur = 3;
                else if(cur == 2) cur = 1;
                else if(cur == 3) cur = 0;
            } else if(direction == 'L') {
                if(cur == 0) cur = 3;
                else if(cur == 1) cur = 2;
                else if(cur == 2) cur = 0;
                else if(cur == 3) cur = 1;
            }
            flag = false;
        }

        x += dx[cur];
        y += dy[cur];

        if(x < 1 || y < 1 || x > N || y > N) break;

        if(board[x][y] == SNAKE) {
            break;
        } else if(board[x][y] == APPLE) {
            board[x][y] = SNAKE;
            snake.push_back({x, y});
        } else {
            board[snake.front().first][snake.front().second] = 0;
            board[x][y] = SNAKE;
            snake.pop_front();
            snake.push_back({x, y});
            tail = snake.front();
        }

        if(m.find(answer) != m.end()) {
            direction = m[answer];
            flag = true;
        }
    }
    cout << answer;
}