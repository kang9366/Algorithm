#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> convert(string str, vector<char> vec_char){
    for(int i=0; i<str.size(); i++){
        if(str[i]!=str[i+1]) vec_char.push_back(str[i]);
    }
    return vec_char;
}

bool check(vector<char> vec_char){
    for(int i=0; i<vec_char.size(); i++){
        for(int j=i; j<vec_char.size()-1; j++) if(vec_char[i]==vec_char[j+1]) return false;
    }
    return true;
}

int main(){
    int num; cin >> num;
    int cnt=0;
    string str;
    vector<string> vec_str;
    vector<char> vec_char;
    for(int i=0; i<num; i++){
        cin >> str;
        if(check(convert(str, vec_char))) cnt++;
        vector<char>().swap(vec_char);
    }
    cout << cnt;
}
