import java.util.Scanner;

public class Main {
    public static int max(int arr[]){
        int max = 0;
        for (int i = 0; i < arr.length; i++){
            if(arr[i] > max) max = arr[i];
        }
        return max;
    }

    public static int min(int arr[]){
        int min = arr[0];
        for (int i = 1; i < arr.length; i++){
            if(arr[i] < min){
                min = arr[i];
            }
        }
        return min;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++){
            arr[i] = sc.nextInt();
        }

        System.out.println(min(arr) + " " + max(arr));
    }
}