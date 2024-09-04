#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S, P;
    cin >> S >> P;

    string str;
    cin >> str;

    int arr[26] = {0};
    int arr2[26] = {0};
    cin >> arr[0] >> arr[2] >> arr[6] >> arr[19];

    deque<char> password;
    deque<char> test;
    for(int i = 0; i < P; i++) {
        password.push_back(str[i]);
        arr2[str[i]-'A']++;
    }

    int answer = 0;
    if(arr2[0]>=arr[0] && arr2[2]>=arr[2] && arr2[6]>=arr[6] && arr2[19]>=arr[19]) answer++;
    for(int i = 1; i <= str.size() - P; i++) {
        if(arr2[password.front()-'A'] != 0) arr2[password.front()-'A']--;
        password.pop_front();
        password.push_back(str[i+P-1]);
        arr2[password.back()-'A']++;
        if(arr2[0]>=arr[0] && arr2[2]>=arr[2] && arr2[6]>=arr[6] && arr2[19]>=arr[19]) answer++;
    }
    cout << answer;
}