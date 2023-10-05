#include <iostream>
#include <string>

using namespace std;

int main(){
    int T;
	string str, word;
    bool flag;
    int cnt;
    for(int i=1; i<=10; i++){
		cin >> T >> word >> str;
        cnt = 0;
        for(int j=0; j<str.size()-word.size(); j++){
            flag = true;
			for(int k=0; k<word.size(); k++){
				if(str[j+k]!=word[k]){
					flag = false;
                    break;
				}
			}
            if(flag){
                cnt++;
            }
        }
        cout << "#" << i << " " << cnt << endl;
    }
}