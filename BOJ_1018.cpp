#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int calculate(vector<char> vec){
    int a=0, b=0;
    string WB = "WBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBW";
    string BW = "BWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWB";
    for(int i=0; i<vec.size(); i++){
        if(vec[i]!=WB[i]) a++;
        if(vec[i]!=BW[i]) b++;
    }
    if(a>b) return b;
    else return a;
}

int main(){
    int N, M; cin >> N >> M;
    char c;
    vector<vector<char>> vec; vector<char> temp;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> c;
            temp.push_back(c);
        }
        vec.push_back(temp);
        vector<char>().swap(temp);
    }
    
    vector<char> newVec;
    vector<int> result;
    for(int i=0; i<=N-8; i++){
        for(int j=0; j<=M-8; j++){
            for(int k=i; k<i+8; k++){
                for(int l=j; l<j+8; l++) newVec.push_back(vec[k][l]);
            }
            result.push_back(calculate(newVec));
            vector<char>().swap(newVec);
        }
    }
    
    sort(result.begin(), result.end());
    cout << result[0] << endl;
}
