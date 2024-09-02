#include <iostream>
#include <vector>

#define MAX 4000000

using namespace std;

typedef long long ll;

bool isPrimeNum(int num) {
	for(int i=2 ; i*i<=num; i++) {
		if(num%i == 0) return false;
	}
	return true;
}

int main() {
    int N;
    cin >> N;
    
    vector<ll> vec;
    
    for(ll i = 2; i <= MAX; i++) {
        if(isPrimeNum(i)) vec.push_back(i);
    }
    
    int start = 0, end = 0;
    int answer = 0;
    ll sum = vec[0];
    
    while(start <= end && end < vec.size()) {
        if(sum > N) {
            sum -= vec[start++];
        } else if(sum < N) {
            sum += vec[++end];
        } else {
            answer++;
            sum += vec[++end];
        }
    }
    cout << answer;
}