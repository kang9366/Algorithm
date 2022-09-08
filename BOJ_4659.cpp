#include <iostream>
#include <string>

using namespace std;

bool isVowel(char ch){
    if(ch=='a'||ch=='i'||ch=='e'||ch=='o'||ch=='u')
        return true;
    else
        return false;
}

bool checkVowel(string str){
    bool check = true;
    if(str.find('a')==std::string::npos&&
       str.find('e')==std::string::npos&&
       str.find('i')==std::string::npos&&
       str.find('o')==std::string::npos&&
       str.find('u')==std::string::npos)
        check = false;
    return check;
}

bool checkThreeContinuous(string str){
    bool check = true;
    if(str.size()==1||str.size()==2){
        return true;
    }
    for(int i=0; i<str.size()-2; i++){
        if((isVowel(str[i])&&isVowel(str[i+1]&&isVowel(str[i+2])))||
           (!isVowel(str[i])&&!isVowel(str[i+1])&&!isVowel(str[i+2]))){
            check = false;
            break;
        }
    }
    return check;
}

bool checkTwoContinuous(string str){
    bool check = true;
    for(int i=0; i<str.size()-1; i++){
        if((str[i]==str[i+1])&&(str[i]!='e')&&(str[i]!='o')){
            check = false;
            break;
        }
    }
    return check;
}

int main(){
    while(true){
        string str; cin >> str;
        if(str=="end") break;
        else{
            if(checkVowel(str)&&checkTwoContinuous(str)&&checkThreeContinuous(str)){
                cout << "<" << str << "> is acceptable." << "\n";
            }else{
                cout << "<" << str << "> is not acceptable." << "\n";
            }
        }
    }
}
