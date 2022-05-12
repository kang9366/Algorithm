import java.util.Scanner;

public class Main {
    public static int func(int k, int n){
        int[][] arr = new int[k][n];
        for (int i = 0; i < k; i++){
            for (int j = 0; j < n; j++){
                if(i==0){
                    arr[i][j] += j+1;
                }else{
                    for (int l = 0; l < j+1; l++){
                        arr[i][j] += arr[i-1][l];
                    }
                }
            }
        }
        return arr[k-1][n-1];
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 0; i < T; i++){
            int k = sc.nextInt(), n = sc.nextInt();
            System.out.println(func(k+1, n));
        }
    }
}