#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int distance(int x1, int x2, int y1, int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int calculate(int x1, int x2, int y1, int y2, int r1, int r2){
    int d = distance(x1,x2,y1,y2);
    if(d==0&&r1==r2) return -1;
    else if(pow(r1+r2,2)==d||pow(r1-r2,2)==d) return 1;
    else if(pow(r1-r2,2)<d&&pow(r1+r2,2)>d) return 2;
    else return 0;
}

int main(){
    int T, x1, x2, y1, y2, r1, r2; cin >> T;
    vector<int> vec;
    for(int i=0; i<T; i++){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        vec.push_back(calculate(x1, x2, y1, y2, r1, r2));
    }
    for(int i=0; i<vec.size(); i++) cout << vec[i] << endl;
}
