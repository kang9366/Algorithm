#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N; cin >> N;
    string str;
    vector<string> vec;
    for(int i=0; i<N; i++){
        cin >> str;
        vec.push_back(str.substr(str.find('.')+1, str.size()));
    }
    sort(vec.begin(), vec.end());
    vector<pair<string, int>> result;
    
    int cnt = 1;
    string temp = vec[0];
    for(int i=1; i<vec.size(); i++){
        if(temp==vec[i]){
            cnt++;
        }else{
            result.push_back(make_pair(temp, cnt));
            temp = vec[i];
            cnt = 1;
        }
    }
    result.push_back(make_pair(temp, cnt));
    
    for(int i=0; i<result.size(); i++){
        cout << result[i].first << " " << result[i].second << "\n";
    }
}
