#include <iostream>
#include <vector>

using namespace std;

int primeNum(int n){
    int num=0; vector<int> vec;
    vec.push_back(0); vec.push_back(0);
    for(int i=2; i<=2*n; i++) vec.push_back(i);
    for(int i=2; i<=2*n; i++){
        if(vec[i]==0) continue;
        for(int j=2*i; j<=2*n; j+=i) vec[j]=0;
    }
    for(int i=n+1; i<=2*n; i++) if(vec[i]!=0) num++;
    return num;
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    while(true){
        cin >> n;
        if(n==0) break;
        cout << primeNum(n) << "\n";
    }
}
