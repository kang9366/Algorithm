#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N; cin >> N;
    string str;
    string arr[N];

    for(int i=0; i<N; i++){
        cin >> str;
        arr[i] = str;
    }
    sort(arr, arr+N);
    
    string temp = arr[0];
    vector<pair<string, int>> vec;
    int cnt = 1;
    for(int i=1; i<N; i++){
        if(arr[i]==temp){
            cnt++;
        }else{
            vec.push_back(make_pair(temp, cnt));
            temp = arr[i+1];
            cnt = 1;
        }
    }
    vec.push_back(make_pair(temp, cnt));
    vector<int> count;
    vector<string> name;
    for(int i=0; i<vec.size(); i++){
        name.push_back(vec[i].first);
        count.push_back(vec[i].second);
    }
    cout << name[max_element(count.begin(), count.end()) - count.begin()];
    
}
