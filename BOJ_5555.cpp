#include <iostream>
#include <string>

using namespace std;

int main(){
    string str, temp; cin >> str;
    int N, cnt = 0; cin >> N;
    for(int i=0; i<N; i++){
        cin >> temp;
        if(temp.find(str)!=std::string::npos){
            cnt++;
        }else{
            for(int i=0; i<temp.size()-1; i++){
                temp += temp[0];
                temp.erase(0, 1);
                if(temp.find(str)!=std::string::npos){
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt;
}
