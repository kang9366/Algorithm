import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {
    //반복문
    public static int fnc1(int arr[]){
        int cnt = 0;
        for (int i = 0; i < arr.length; i++){
            for (int j = i+1; j < arr.length; j++){
                if(arr[i]==arr[j]) arr[i] = 43;
            }
            if(arr[i]!=43) cnt++;
        }
        return cnt;
    }//

    //HashSet 사용 --> Set은 값의 중복 허용x
    public static int fnc2(int[] arr){
        HashSet<Integer> set = new HashSet<Integer>();
        for (int i = 0; i < arr.length; i++){
            set.add(arr[i]);
        }
        System.out.println(set);
        return set.size();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[10];
        int cnt = 0;
        for (int i = 0; i < arr.length; i++){
            arr[i] = Integer.parseInt(br.readLine());
            arr[i] = arr[i]%42;
        }
        //System.out.println(fnc1(arr));
        System.out.println(fnc2(arr));
    }
}