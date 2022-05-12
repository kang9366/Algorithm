import java.util.Scanner;
import java.util.stream.Stream;

public class Main {
    static int noname(int N){
        int result=0;
        int temp;
        for (int i = 0; i < N; i++){
            int sum = i;
            int[] arrNum = Stream.of(String.valueOf(i).split("")).mapToInt(Integer::parseInt).toArray();
            for (int j = 0; j < arrNum.length; j++){
                sum += arrNum[j];
            }
            if(sum==N){
                result = i;
                break;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        if(N<1 || N>1000000) System.exit(0);
        System.out.println(noname(N));
    }
}