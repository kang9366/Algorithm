import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt(), y = sc.nextInt(), w = sc.nextInt() - x, h = sc.nextInt() - y, min;
        int[] arr = {x, y, w, h};
        min = arr[0];
        for (int i = 0; i < arr.length; i++){
            if(arr[i] < min) min = arr[i];
        }
        System.out.println(min);
    }
}