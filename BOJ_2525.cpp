#include <iostream>
#include <random>

using namespace std;

int main(){
    int hour, min, time;
    cin >> hour;
    cin >> min;
    cin >> time;
    
    int temp = (min + time) / 60;
    
    if(temp + hour > 23){
        cout << temp + hour - 24 << " " << min + time - temp*60;
    }else if(temp > 0 && temp + hour < 24){
        cout << hour+temp << " " << min + time - temp*60;
    }else{
        cout << hour << " " << min+time;
    }
}
