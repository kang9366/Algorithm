#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

#define MAX 100

using namespace std;

typedef pair<int, int> coordinate;

int N, M;
int map[MAX][MAX];

vector<coordinate> chicken;
vector<coordinate> house;
vector<int> answer;

int arr[MAX][MAX];

void chicken_distance(int index, coordinate house) {
    int distance;

    for(int i = 0; i < chicken.size(); i++) {
        distance = 0;
        distance += abs(chicken[i].first - house.first);
        distance += abs(chicken[i].second - house.second);
        arr[index][i] = distance;
    }
}

void permutation() {
    vector<bool> selected (chicken.size(), false);
    fill(selected.begin(), selected.begin() + M, true);

    do {
        vector<int> temp;
        for(int i = 0; i < selected.size(); i++) {
            if(selected[i]) {
                temp.push_back(i);
            }
        }

        int distance = 0;

        for(int i = 0; i < house.size(); i++) {
            vector<int> distance_vec;
            for(auto &j : temp) {
                distance_vec.push_back(arr[i][j]);
            }
            distance += *min_element(distance_vec.begin(), distance_vec.end());
        }
        answer.push_back(distance);
    } while (prev_permutation(selected.begin(), selected.end()));
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) { chicken.push_back({i, j}); }
            if(map[i][j] == 1) { house.push_back({i, j}); }
        }
    }

    for(int i = 0; i < house.size(); i++) {
        chicken_distance(i, house[i]);
    }

    permutation();
    cout << *min_element(answer.begin(), answer.end());
}
