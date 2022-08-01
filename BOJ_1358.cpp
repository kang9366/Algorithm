#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int W, H, X, Y, P; cin >> W >> H >> X >> Y >> P;
    int x, y, cnt=0;
    for(int i=0; i<P; i++){
        cin >> x >> y;
        int r1 = pow((x-X), 2) + pow((y-(Y+H/2)),2);
        int r2 = pow((x-(X+W)), 2) + pow((y-(Y+H/2)),2);
        if(x>=X && x<=X+W && y>=Y && y<=Y+H) cnt++;
        else if(r1 <= pow(H/2, 2) || r2 <= pow(H/2, 2)) cnt++;
    }
    cout << cnt;
}
