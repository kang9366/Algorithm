#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    int result;
    for(int i=1; i<=10; i++){
        cin >> N;
        int arr[N];
        result = 0;
        for(int j=0; j<N; j++) cin >> arr[j];

        for(int j=0; j<N; j++){
            if(j==0){
                if(arr[0]>arr[1] && arr[0]>arr[2]){
                    result += arr[0]-max(arr[1], arr[2]);
                }
            }else if(j==1){
                if(arr[1]>arr[0] && arr[1]>arr[2] && arr[1]>arr[3]){
                    result += arr[1]-max({arr[0], arr[2], arr[3]});
                }
            }else if(j==N-1){
                if(arr[N-1]>arr[N-2] && arr[N-1]>arr[N-3]){
                    result += arr[N-1]-max(arr[N-2], arr[N-3]);
                }
            }else if(j==N-2){
                if(arr[N-2]>arr[N-1] && arr[N-2]>arr[N-3] && arr[N-2]>arr[N-4]){
                    result += arr[N-2]-max({arr[N-1], arr[N-2], arr[N-3]});
                }
            }else{
                if(arr[j]>arr[j+1] && arr[j]>arr[j+2]
                    && arr[j]>arr[j-1] && arr[j]>arr[j-2]){
                        result += arr[j]-max({arr[j-1], arr[j-2], arr[j+1], arr[j+2]});
                    }
            }
        }
        cout << "#" << i << " " << result << endl;
    }
}