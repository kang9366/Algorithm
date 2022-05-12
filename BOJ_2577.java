import java.util.stream.Stream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
    public static int[] calculate(int arr[]){
        int[] cnt = new int[10];
        for (int i = 0; i < arr.length; i++){
            if(arr[i]==0) cnt[0]++;
            else if(arr[i]==1) cnt[1]++;
            else if(arr[i]==2) cnt[2]++;
            else if(arr[i]==3) cnt[3]++;
            else if(arr[i]==4) cnt[4]++;
            else if(arr[i]==5) cnt[5]++;
            else if(arr[i]==6) cnt[6]++;
            else if(arr[i]==7) cnt[7]++;
            else if(arr[i]==8) cnt[8]++;
            else if(arr[i]==9) cnt[9]++;
        }
        return cnt;
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int A = Integer.parseInt(br.readLine());
        int B = Integer.parseInt(br.readLine());
        int C = Integer.parseInt(br.readLine());
        int num = A*B*C;
        int[] arrNum = Stream.of(String.valueOf(num).split("")).mapToInt(Integer::parseInt).toArray();
        for (int i = 0; i < calculate(arrNum).length; i++){
            System.out.println(calculate(arrNum)[i]);
        }
    }
}