#include <iostream>

using namespace std;

int main(){
    int N, team, A=0, B=0;
    string time;
    cin >> N;
    

    for(int i=0; i<N; i++){
        cin >> team;
        if(team==1){
            A++;
        }else{
            B++;
        }
        cin >> time;
    }
}