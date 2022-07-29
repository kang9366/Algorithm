#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    int N, temp; cin >> N;
    vector<int> vec;
    for(int i=0; i<N; i++){
        cin >> temp;
        vec.push_back(temp);
    }
    for(int i=1; i<vec.size(); i++) cout << vec[0]/gcd(vec[0], vec[i]) << "/" << vec[i]/gcd(vec[0], vec[i]) << endl;
}
