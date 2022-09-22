#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int M, N; cin >> M >> N;
    string arr[10] = {"zero" ,"one" ,"two" ,"three" ,"four" ,"five" ,"six" ,"seven" ,"eight" ,"nine"};
    string temp;
    vector<pair<string ,int>> vec;
    
    for(int i=M; i<=N; i++){
        if(i>=10){
            temp = arr[i/10] + " " + arr[i%10];
            vec.push_back(make_pair(temp, i));
        }
        else{
            temp = arr[i];
            vec.push_back(make_pair(temp, i));
        }
    }
    
    sort(vec.begin(), vec.end());
    
    for(int i=0; i<vec.size(); i++){
        if(i!=0&&i%10==0) cout << endl;
        if(i==vec.size()-1) cout << vec[i].second;
        else cout << vec[i].second << " ";
    }
}
