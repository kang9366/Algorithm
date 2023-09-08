#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, x, y;
	vector<pair<int, int>> vec;

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> x >> y;
		vec.push_back(make_pair(x, y));
	}

	sort(vec.begin(), vec.end());

	for(int i=0; i<N; i++){
		cout << vec[i].first << " " << vec[i].second << endl;
	}
}