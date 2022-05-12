import java.util.Scanner;

public class Main {
    public static int[] array(int n, int m){
        int[] arr = new int[m-n+1];
        for (int i = 0; i < arr.length; i++){
            arr[i] = n++;
        }
        return arr;
    }

    public static void primeNumber(int[] arr){
        System.out.println(Math.sqrt(arr[arr.length-1])-1);
        for (int i = 2; i < Math.sqrt(arr[arr.length-1])-1; i++){
            for (int j = 0; j < arr.length; j++){

            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        primeNumber(array(n, m));
    }
}