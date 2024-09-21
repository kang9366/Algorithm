#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string str;
    cin >> str;

    bool f1 = false, f2 = false, f3 = false, f4 = false;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

    for(int i = 0; i < str.size(); i++) {
        // Red -> Left
        if(str[i] == 'B') f1 = true;
        if(f1 && str[i] == 'R') c1++;

        // Red -> Right
        if(str[str.size()-i-1] == 'B') f2 = true;
        if(f2 && str[str.size()-i-1] == 'R') c2++;

        // Blue -> Left
        if(str[i] == 'R') f3 = true;
        if(f3 && str[i] == 'B') c3++;

        // Blue -> Right
        if(str[str.size()-i-1] == 'R') f4 = true;
        if(f4 && str[str.size()-i-1] == 'B') c4++;
    }
    cout << min({c1, c2, c3, c4});
}