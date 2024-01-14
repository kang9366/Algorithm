#include <iostream>
#include <queue>
#include <string>

#define MAX 100

using namespace std;



vector<string> vec;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool visited1[MAX][MAX] = {false, };
bool visited2[MAX][MAX] = {false, };

queue<pair<int, int>> q1, q2;

int N;

void solution() {
	int cnt1 = 0, cnt2 = 0;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(!visited1[i][j]) {
				q1.push({i, j});
				visited1[i][j] = true;

				while(!q1.empty()) {
					pair<int, int> cur = q1.front();
					q1.pop();
				
					char ch = vec[cur.first][cur.second];
				
					for(int k = 0; k < 4; k++ ){
						int nx = cur.first + dx[k];
						int ny = cur.second + dy[k];

						if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

						if(!visited1[nx][ny] && vec[nx][ny] == ch) {
							q1.push({nx, ny});
							visited1[nx][ny] = true;
						}
					}
				}
				cnt1++;
			}

			if(!visited2[i][j]) {
				q2.push({i, j});
				visited2[i][j] = true;

				while(!q2.empty()) {
					pair<int, int> cur = q2.front();
					q2.pop();

					char ch = vec[cur.first][cur.second];

					for(int k = 0; k < 4; k++) {
						int nx = cur.first + dx[k];
						int ny = cur.second + dy[k];

						if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;


						if(!visited2[nx][ny]) {
							if(ch == 'R' || ch == 'G') {
								if(vec[nx][ny] == 'R' || vec[nx][ny] == 'G') {
									q2.push({nx, ny});
									visited2[nx][ny] = true;
								}
							} else {
								if(vec[nx][ny] == 'B') {
									q2.push({nx, ny});
									visited2[nx][ny] = true;
								}
							}
						}
					}
				}
				cnt2++;
			}
		}
	}
	cout << cnt1 << " " << cnt2;
}

int main() {
	string str;
	cin >> N;

	for(int i = 0; i < N; i++) {
		cin >> str;
		vec.push_back(str);
	}

	solution();
}