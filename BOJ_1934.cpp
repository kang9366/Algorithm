#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num, a, b; cin >> num;
    vector<int> vec;
    for(int i=0; i<num; i++){
        cin >> a; cin >> b;
        vec.push_back(a * b / gcd(a,b));
    }
    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << endl;
    }
}
