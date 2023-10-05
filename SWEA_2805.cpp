#include <iostream>

using namespace std;

int main(){
	int T, N, result;
    cin >> T;
    for(int i=0; i<T; i++){
		cin >> N;
        int arr[N][N];
        result = 0;
        
        for(int j=0; j<N; j++){
            for(int k=0; i<N; k++){
                cin >> arr[j][k];
            }
        }
        
        for(int j=(N-1)/2; j<N; j++){
            result = 0;
            int l = 0;
            for(int k=(N-1)/2; k<N; k++){
                if(l==0){
	                result += arr[j][k];
                }else{
                    result += (arr[j][k] + arr[j][k-l]);
                }
                l++;
            }
            cout << result << endl;
        }
    }
}