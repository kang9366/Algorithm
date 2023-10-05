#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T, N, M, max;
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N >> M;
        int arr[N][N];
        max = 0;
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                cin >> arr[j][k];
            }
        }

        int temp=0;
        for(int j=0; j<=N-M; j++){
            for(int k=0; k<=N-M; k++){
                for(int l=j; l<j+M; l++){
                    for(int m=k; m<k+M; m++){
                        temp += arr[l][m];
                    }
                }
                if(temp>max) max=temp;
                temp = 0;
            }
        }
        cout << "#" << i+1 << " " << max << endl;
    }
}