#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(string a, string b){
    if(a.length() == b.length()){
        return a<b;
    }else{
        return a.length() < b.length();
    }
}

string vec[20000];

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> vec[i];
    }
    sort(vec, vec+N, cmp);
    for(int i=0; i<N; i++){
        if(vec[i]==vec[i-1]){
            continue;
        }else{
            cout << vec[i] << endl;
        }
    }
}