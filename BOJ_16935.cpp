#include <iostream>
#include <vector>

using namespace std;

int arr[100][100];
int temp[100][100];

int temp_one[100][100];
int temp_two[100][100];
int temp_three[100][100];
int temp_four[100][100];

int N, M, R;

void copy() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            temp[i][j] = arr[i][j];
        }
    }
}

void one() {
    copy();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            arr[i][j] = temp[N-i-1][j];
        }
    }
}

void two() {
    copy();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            arr[i][j] = temp[i][M-j-1];
        }
    }
}

void three() {
    copy();
    swap(N, M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            arr[i][j] = temp[M-j-1][i];
        }
    }
}

void four() {
    copy();
    swap(N, M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            arr[i][j] = temp[j][N-i-1];
        }
    }
}

void five() {
    copy();
    for(int i = 0; i < N/2; i++) {
        for(int j = 0; j < M/2; j++) {
            arr[i][j] = temp[i+N/2][j];
        }
    }

    for(int i = 0; i < N/2; i++) {
        for(int j = M/2; j < M; j++) {
            arr[i][j] = temp[i][j-M/2];
        }
    }

    for(int i = N/2; i < N; i++) {
        for(int j = M/2; j < M; j++) {
            arr[i][j] = temp[i-N/2][j];
        }
    }

    for(int i = N/2; i < N; i++) {
        for(int j = 0; j < M/2; j++) {
            arr[i][j] = temp[i][j+M/2];
        }
    }
}

void six() {
    copy();
    for(int i = 0; i < N/2; i++) {
        for(int j = 0; j < M/2; j++) {
            arr[i][j] = temp[i][j+M/2];
        }
    }

    for(int i = 0; i < N/2; i++) {
        for(int j = M/2; j < M; j++) {
            arr[i][j] = temp[i+N/2][j];
        }
    }

    for(int i = N/2; i < N; i++) {
        for(int j = M/2; j < M; j++) {
            arr[i][j] = temp[i][j-M/2];
        }
    }

    for(int i = N/2; i < N; i++) {
        for(int j = 0; j < M/2; j++) {
            arr[i][j] = temp[i-N/2][j];
        }
    }
}

int main() {
    cin >> N >> M >> R;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < R; i++) {
        int temp;
        cin >> temp;
        if(temp == 1) one();
        else if(temp == 2) two();
        else if(temp == 3) three();
        else if(temp == 4) four();
        else if(temp == 5) five();
        else if(temp == 6) six();
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}