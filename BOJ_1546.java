import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        float[] arr = new float[N];
        float max = 0;
        float sum = 0;
        
        for (int i = 0; i < N; i++){
            arr[i] = sc.nextFloat();
            if(arr[i] > max) max = arr[i];
        }
        for (int i = 0; i < N; i++){
            arr[i] = arr[i]/max*100;
            sum += arr[i];
        }
        System.out.println(sum/N);
    }
}
