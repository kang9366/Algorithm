#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define endl "\n"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L, C;
    cin >> L >> C;

    char arr[C];
    for(int i = 0; i < C; i++) {
        cin >> arr[i];
    }

    vector<bool> select(C);
    fill(select.end() - L, select.end(), true);

    vector<string> answer;
    do {
        string temp = "";
        for(int i = 0; i < C; i++) {
            if(select[i]) temp += arr[i];
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp);
    } while(next_permutation(select.begin(), select.end()));

    sort(answer.begin(), answer.end());
    for(auto &i : answer) {
        int consonant = 0;
        int vowels = 0;
        for(auto &j : i) {
            if(j == 'a' || j == 'i' || j == 'e' || j == 'o' || j == 'u') {
                vowels++;
            } else {
                consonant++;
            }
        }

        if(vowels >= 1 && consonant >= 2) cout << i << endl;
    }
}