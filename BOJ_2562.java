import java.util.Scanner;

public class Main {
    public static int[] max(int[] arr){
        int[] result = new int[2];
        int max = 0;
        for (int i = 0; i < arr.length; i++){
            if(arr[i] > max) max = arr[i];
        }
        result[0] = max;
        for (int i = 0; i < arr.length; i++){
            if(max == arr[i]) result[1] = i+1;
        }
        return result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[9];
        for (int i = 0; i < arr.length; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(max(arr)[0]);
        System.out.println(max(arr)[1]);
    }
}