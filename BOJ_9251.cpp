#include <iostream>
#include <string>

#define MAX 1001

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1;
    string str2;

    cin >> str1 >> str2;

    str1 = " " + str1;
    str2 = " " + str2;

    int dp[MAX][MAX];
    int answer = 0;

    for(int i = 1; i < str1.size(); i++) {
        for(int j = 1; j < str2.size(); j++) {
            if(str1[i] == str2[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[str1.size()-1][str2.size()-1];
}