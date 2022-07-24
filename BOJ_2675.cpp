#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int num; cin >> num;
    string str;
    int cnt;
    vector<string> vec1;
    vector<int> vec2;
    for(int i=0; i<num; i++){
        cin >> cnt;
        cin >> str;
        vec1.push_back(str);
        vec2.push_back(cnt);
    }
    for(int i=0; i<vec1.size(); i++){
        for(int j=0; j<vec1[i].size(); j++){
            for(int k=0; k<vec2[i]; k++) cout << vec1[i][j];
        }
        cout << endl;
    }
}
