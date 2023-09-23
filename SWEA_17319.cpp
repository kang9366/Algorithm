#include <iostream>
#include <string>

using namespace std;

bool compare(string str, int N){
    string str1, str2;
    for(int i=0; i<N/2; i++){
     	   str1 += str[i];
           str2 += str[i+N/2];
    }
    if(str1==str2){
        return true;
    }else{
        return false;
    }
}

int main(){
    int TC, N;
    string str;

	cin >> TC;

    
    for(int i=0; i<TC; i++){
 		cin >> N >> str;
        if(N%2==0){
            if(compare(str, N)){
                cout << "#" << i+1 << " " << "Yes" << endl;
            }else{
                cout << "#" << i+1 << " " << "No" << endl;
            }
        }else{
            cout << "#" << i+1 << " " << "No" << endl;
        }
    }
}