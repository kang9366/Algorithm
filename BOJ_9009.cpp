#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
vector<int> result;
long long dp[10000] = {0,};

void fibo(int num){
    int i=2;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    vec.push_back(1);
    vec.push_back(1);
    while(true){
        dp[i] = dp[i-1] + dp[i-2];

        if(dp[i]>num){
            break;
        }else{
            vec.push_back(dp[i]);
            i++;
        }
    }
}

void solve(int num){
    for(int i=0; i<vec.size(); i++){
        if(num>=vec[i]){
            result.push_back(vec[i]);
            num -= vec[i];
        }
    }
}

int main(){
    int T, n;
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> n;
        fibo(n);
        sort(vec.begin(), vec.end(), greater<>());
        solve(n);
        sort(result.begin(), result.end());
        for(auto&j : result)
            cout << j << " ";
        vec.clear();
        result.clear();
    }
}