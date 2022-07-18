#include <iostream>
#include <vector>

using namespace std;

int main(){
    int A, B;
    vector<int> vec;
    while(true){
        cin >> A >> B;
        if(A!=0&&B!=0) vec.push_back(A+B);
        else{
            for(int i=0; i<vec.size(); i++) cout << vec[i] << endl;
            break;
        }
    }
}
