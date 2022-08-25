#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<bool> vec;
    vec.assign(10000, true);
    int num=1, a, b, c, d, temp;
    while(num<10000){
        a=num/1000, b=(num-a*1000)/100, c=(num-a*1000-b*100)/10, d=(num-a*1000-b*100-c*10);
        temp = num+a+b+c+d;
        vec[temp]=false;
        num++;
    }
    
    for(int i=1; i<vec.size(); i++) if(vec[i]) cout << i << endl;
}
