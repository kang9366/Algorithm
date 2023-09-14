#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N, temp;
	cin >> N;
	vector<int> vec;
	for(int i=0; i<N; i++){
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());

	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for(int i=0; i<vec.size(); i++){
		cout << vec[i] << " ";
	}
}