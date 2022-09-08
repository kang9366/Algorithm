#include <iostream>
#include <string>

using namespace std;

int main(){
    string str; cin >> str;
    bool cpp = false, java = false;
    
    if(str[0]=='_'||str[str.size()-1]=='_'||(str[0]>=65&&str[0]<=90)){
        cout << "Error!";
        exit(0);
    }
     
    for(int i=0; i<str.size()-1; i++){
        if(str[i]=='_'&&str[i+1]=='_'){
            cout << "Error!";
            exit(0);
        }
        else if(str[i]=='_' && (str[i+1]>=65&&str[i+1]<=90)){
            cout << "Error!";
            exit(0);
        }
    }
    
    
    if(str.find('_')==std::string::npos)
        java = true;
    else
        cpp = true;
    
    
    if(cpp){
        for(int i=0; i<str.size(); i++){
            if(str[i]>=65&&str[i]<=90){
                cout << "Error!";
                exit(0);
            }
            if(str[i]=='_'){
                str.erase(str.begin()+i);
                str[i] = toupper(str[i]);
            }
        }
        cout << str;
    }else if(java){
        for(int i=0; i<str.size(); i++){
            if(str[i]=='_'){
                cout << "Error!";
                exit(0);
            }
            if(str[i]>=65&&str[i]<=90){
                str.insert(i, "_");
                str[i+1] = tolower(str[i+1]);
            }
        }
        cout << str;
    }
}
