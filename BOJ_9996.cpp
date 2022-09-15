#include <iostream>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N; cin >> N;
    string pattern; cin >> pattern;
    int index = pattern.find('*');
    auto begin = pattern.substr(0, index);
    auto end = pattern.substr(index+1, pattern.size());
    
    string str;
    for(int i=0; i<N; i++){
        cin >> str;
        if(str.substr(0,begin.size())==begin && str.substr(str.size()-end.size(), str.size())==end)
            cout << "DA" << "\n";
        else
            cout << "NE" << "\n";
    }
}
