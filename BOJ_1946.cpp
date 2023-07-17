#include <iostream>
#include <string>

using namespace std;

char min(char ch){
    if(ch=='6'){
        return '5';
    }else{
        return ch;
    }
}

char max(char ch){
    if(ch=='5'){
        return '6';
    }else{
        return ch;
    }
}

int main(){
    string A, B;
    string minA = "", minB = "", maxA ="", maxB = "";
    cin >> A >> B;
    
    for(int i=0; i<size(A); i++) {
        minA += min(A[i]);
        maxA += max(A[i]);
    }

    for(int i=0; i<size(B); i++) {
        minB += min(B[i]);
        maxB += max(B[i]);
    }

    cout << stoi(minA) + stoi(minB) << " " << stoi(maxA) + stoi(maxB);
}