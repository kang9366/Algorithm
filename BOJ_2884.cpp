#include <iostream>

using namespace std;

int main (){
    int hour, min;
    const int time = 45;
    cin >> hour;
    cin >> min;
    
    if(hour==0 && min < 45){
        cout << 23 << " " << 60 - (time - min);
    }else if(min - time < 0){
        cout << hour - 1 << " " << 60 - (time - min);
    }else{
        cout << hour << " " << min - time;
    }
}
