#include <iostream>
#include <vector>

using namespace std;

vector<int> primeNum(int n){
    vector<int> temp, vec;
    temp.push_back(0); temp.push_back(0);
    for(int i=2; i<=n; i++) temp.push_back(i);
    for(int i=2; i<=n; i++){
        if(temp[i]==0) continue;
        for(int j=2*i; j<=n; j+=i) temp[j]=0;
    }
    for(int i=0; i<temp.size(); i++) if(temp[i]!=0) vec.push_back(i);
    return vec;
}

void func(vector<int> vec, int n){
    int a, b, temp=0;
    for(int i=0; i<vec.size(); i++){
        if(vec[i]*2==n){
            cout << vec[i] << " " << vec[i] << "\n";
            break;
        }else{
            if(i==vec.size()-1){
                cout << a << " " << b << "\n";
                break;
            }else{
                for(int j=i+1; j<vec.size(); j++){
                    if(vec[i]+vec[j]==n){
                        if(temp==0){
                            a = vec[i];
                            b = vec[j];
                            temp = a - b;
                        }else{
                            if(temp<vec[i]-vec[j]){
                                a = vec[i];
                                b = vec[j];
                                temp = a - b;
                            }else{
                                continue;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, T;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> n;
        func(primeNum(n), n);
    }
}
