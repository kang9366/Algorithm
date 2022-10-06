#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
    string str; cin >> str;
    string first, second;
    if(str=="0"){
        cout << "W";
    }else if(str.find('+')!=string::npos){
        if(str[0]=='x'){
            first = "1";
            second = str.substr(str.find('+')+1, str.size());
            if(stoi(second)==1)
                cout << stoi(first)*0.5 << "xx+x+W";
            else if(stoi(second)==0)
                cout << stoi(first)*0.5 << "xx+W";
            else
                cout << stoi(first)*0.5 << "xx+" << stoi(second) << "x+W";
        }else if(str[0]=='-'&&str[1]=='x'){
            first = "-1";
            second = str.substr(str.find('+')+1, str.size());
            if(stoi(second)==1)
                cout << stoi(first)*0.5 << "xx+x+W";
            else if(stoi(second)==0)
                cout << stoi(first)*0.5 << "xx+W";
            else
                cout << stoi(first)*0.5 << "xx+" << stoi(second) << "x+W";
        }else{
            first = str.substr(0, str.find('+')-1);
            second = str.substr(str.find('+')+1, str.size());
            if(stoi(first)==2)
                if(stoi(second)==1)
                    cout << "xx+x+W";
                else if(stoi(second)==0)
                    cout << "xx+W";
                else
                    cout << "xx+" << stoi(second) << "x+W";
            else if(stoi(first)==-2)
                if(stoi(second)==1)
                    cout << "-xx+x+W";
                else if(stoi(second)==0)
                    cout << "-xx+W";
                else
                    cout << "-xx+" << stoi(second) << "x+W";
            else
                if(stoi(second)==1)
                    cout << stoi(first)*0.5 << "xx+x+W";
                else if(stoi(second)==0)
                    cout << stoi(first)*0.5 << "xx+W";
                else
                    cout << stoi(first)*0.5 << "xx+" << stoi(second) << "x+W";
        }
    }else if(str.find('-')!=string::npos&&str.find_last_of('-')!=0){
        if(str[0]=='x'){
            first = "1";
            second = str.substr(str.find('-')+1, str.size());
            if(stoi(second)==1)
                cout << stoi(first)*0.5 << "xx-x+W";
            else if(stoi(second)==0)
                cout << stoi(first)*0.5 << "xx+W";
            else
                cout << stoi(first)*0.5 << "xx-" << stoi(second) << "x+W";
        }else if(str[0]=='-'&&str[1]=='x'){
            first = "-1";
            second = str.substr(str.find_last_of('-')+1, str.size());
            if(stoi(second)==1)
                cout << stoi(first)*0.5 << "xx-x+W";
            else if(stoi(second)==0)
                cout << stoi(first)*0.5 << "xx+W";
            else
                cout << stoi(first)*0.5 << "xx-" << stoi(second) << "x+W";
        }else{
            first = str.substr(0, str.find_last_of('-')-1);
            second = str.substr(str.find_last_of('-')+1, str.size());
            if(stoi(first)==2)
                if(stoi(second)==1)
                    cout << "xx-x+W";
                else if(stoi(second)==0)
                    cout << "xx+W";
                else
                    cout << "xx-" << stoi(second) << "x+W";
            else if(stoi(first)==-2)
                if(stoi(second)==1)
                    cout << "-xx-x+W";
                else if(stoi(second)==0)
                    cout << "-xx+W";
                else
                    cout << "-xx-" << stoi(second) << "x+W";
            else
                if(stoi(second)==1)
                    cout << stoi(first)*0.5 << "xx-x+W";
                else if(stoi(second)==0)
                    cout << stoi(first)*0.5 << "xx+W";
                else
                    cout << stoi(first)*0.5 << "xx-" << stoi(second) << "x+W";
        }
    }else if(str.find('x')==string::npos){
        if(stoi(str)==1)
            cout << "x+W";
        else if(stoi(str)==-1)
            cout << "-x+W";
        else
            cout << str << "x+W";
    }else{
        if(str[0]=='x')
            cout << 0.5 << "xx+W";
        else if(str[0]=='-'&&str[1]=='x')
            cout << -0.5 << "xx+W";
        else{
            first = str.substr(0, str.find('x'));
            if(stoi(first)==2)
                cout << "xx+W";
            else if(stoi(first)==-2)
                cout << "-xx+W";
            else
                cout << stoi(first)*0.5 << "xx+W";
        }
    }
}
