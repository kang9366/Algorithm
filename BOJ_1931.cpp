#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> a, const pair<int, int> b){
    if(a.second==b.second){
        return a.first<b.first;
    }else{
        return a.second<b.second;
    }
}

int main(){
    int N, f, s, cnt=1;
    cin >> N;
    vector<pair<int, int>> vec;

    for(int i=0; i<N; i++){
        cin >> f >> s;
        vec.push_back(make_pair(f, s));
    }

    sort(vec.begin(), vec.end(), cmp);
    
    int ret = vec[0].second;

    for(int i=0; i<N-1; i++){
        if(ret<=vec[i+1].first){
            ret = vec[i+1].second;
            cnt++;
        }else{
            continue;
        }
    }
    cout << cnt;
}