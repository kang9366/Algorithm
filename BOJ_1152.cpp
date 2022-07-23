#include <iostream>
#include <string>

using namespace std;

int func(string str, int cnt){
    for(int i=0; i<str.size(); i++) if(((int)str[i])==32) cnt++;
    return cnt;
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int result; string str;
    getline(cin, str);
    if(((int)str.front()==32&&str.size()==1)||(str.length()==2&&(int)str.front()==32 && (int)str.back()==32)) result=0;
    else if((int)str.front()==32 && (int)str.back()==32) result = func(str, -1);
    else if((int)str.front()==32 || (int)str.back()==32) result = func(str,0);
    else result = func(str, 1);
    cout << result;
}
