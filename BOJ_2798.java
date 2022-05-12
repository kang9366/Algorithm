import java.util.Scanner;

public class Main {
    static int search(int[] arr, int N, int M){
        int result = 0;
        int temp;
        for (int i = 0; i < N-2; i++){
            for (int j = i+1; j < N-1; j++){
                for(int k = j+1; k < N; k++){
                    temp = arr[i] + arr[j] + arr[k];
                    if(temp==M){
                        result = temp;
                    } else if(temp > result && temp < M){
                        result = temp;
                    }
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), M = sc.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(search(arr, N, M));
    }
}