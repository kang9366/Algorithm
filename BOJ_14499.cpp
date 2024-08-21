#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

vector<int> dice(6);
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void east() {
    dice = { dice[3], dice[1], dice[0], dice[5], dice[4], dice[2] };
}

void west() {
    dice = { dice[2], dice[1], dice[5], dice[0], dice[4], dice[3] };
}

void north() {
    dice = { dice[4], dice[0], dice[2], dice[3], dice[5], dice[1] };
}

void south() {
     dice = { dice[1], dice[5], dice[2], dice[3], dice[0], dice[4] };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, x, y, K;
    cin >> N >> M >> y >> x >> K;

    int map[N][M];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int order[K];
    for(int i = 0; i < K; i++) cin >> order[i];

    for(int i = 0; i < K; i++) {
        int nx, ny;
        nx = x + dx[order[i]-1];
        ny = y + dy[order[i]-1];
        if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
        x = nx;
        y = ny;

        switch(order[i]) {
            case 1:
                east();
                break;
            case 2:
                west();
                break;
            case 3:
                north();
                break;
            case 4:
                south();
                break;
            defalut:
                break;
        }

        if(map[ny][nx] == 0) {
            map[ny][nx] = dice[5];
        } else {
            dice[5] = map[ny][nx];
            map[ny][nx] = 0;
        }

        cout << dice[0] << endl;       
    }
}