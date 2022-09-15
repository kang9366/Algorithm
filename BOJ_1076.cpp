#include <iostream>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    if(str.size()<3){
        cout << "none";
        exit(0);
    }
    string happy = ":-)", sad = ":-(";
    int cnt_happy=0, cnt_sad=0;
    
    for(int i=0; i<str.size()-3; i++){
        if(str[i]==happy[0]&&str[i+1]==happy[1]&&str[i+2]==happy[2])
            cnt_happy++;
        else if(str[i]==sad[0]&&str[i+1]==sad[1]&&str[i+2]==sad[2])
            cnt_sad++;
    }
    
    if(cnt_happy==0&&cnt_sad==0)
        cout << "none";
    else if(cnt_happy==cnt_sad)
        cout << "unsure";
    else if(cnt_happy > cnt_sad)
        cout << "happy";
    else if(cnt_sad > cnt_happy)
        cout << "sad";
}
