#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<int> vec(26, -1);
    vector<int> str;
    string S; cin >> S;
    for(int i=0; i<S.size(); i++) str.push_back((int) S[i] - 97);
    for(int i=0; i<str.size(); i++){
        for(int j=i; j<str.size()-1; j++) if(str[i]==str[j+1]) str[j+1] = -1;
    }
    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<str.size(); j++) if(i==str[j]) vec[i] = j;
    }
    for(int i=0; i<vec.size(); i++) cout << vec[i] << endl;
}
