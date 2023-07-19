#include <iostream>
#include <string>

using namespace std;

bool isFirst = true, flag = false;
int result = 0;
string str, temp = "";


void func(){
    if(flag){
        result -= stoi(temp);
    }else{
        result += stoi(temp);
    }    
}

int main(){    
    cin >> str;
    void (*f)();
    
    f = func;
    
    for(int i=0; i<size(str); i++){
        if(i==size(str)-1){
            temp += str[i];
            f();
            cout << result;

        }else if(str[i]!='+' && str[i]!='-'){
            temp += str[i];
        }else{
            if(isFirst){
                isFirst = false;
                result += stoi(temp);
                temp = "";
                if(str[i]=='-'){
                    flag = true;
                }
            }else{
                if(str[i]=='+'){
                    f();
                    temp = "";
                }else if(str[i]=='-'){
                    f();
                    flag = true;
                    temp = "";
                }
            }
        }
    }
}