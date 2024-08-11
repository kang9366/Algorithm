#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
string word;
map<string, int> m;
vector<pair<string, int>> vec;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
	if(a.second == b.second) {
		if(a.first.length() == b.first.length()) {
			return a.first < b.first;
		} else {
			return a.first.length() > b.first.length();
		}
	} else {
		return a.second > b.second;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for(int i = 0; i < N; i++) {
		cin >> word;
		if(word.length() < M) continue;
		if(m.find(word) != m.end()) m[word]++;
		else m.insert({word, 1});
	}

	for (auto& it : m) vec.emplace_back(it);
	sort(vec.begin(), vec.end(), cmp);
	for(auto &iter: vec) cout << iter.first << '\n';
}