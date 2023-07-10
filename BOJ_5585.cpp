#include <iostream>
#include <vector>

#define MONEY 1000

using namespace std;

int main(){
    int price, change, temp;
    vector<int> vec = {500, 100, 50, 10, 5, 1};
    cin >> price;
    change = MONEY - price;

    int result = 0;

    for(int i=0; i<size(vec); i++){
        temp = change / vec[i];
        result += temp;
        change = change - temp*vec[i];
    }
    cout << result;
}