import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
//
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] arr = new String[n];
        for (int i = 0; i < n; i++){
            arr[i] = br.readLine();
            char[] arr_char = new char[arr[i].length()];
            int[] arr_int = new int[arr[i].length()];
            int sum = 0;
            for (int j = 0; j < arr_char.length; j++){
                arr_char[j] = arr[i].charAt(j);
                if(j!=0){
                    if(arr_char[j]=='O'&&arr_char[j-1]=='O'){
                        arr_int[j] = arr_int[j-1] + 1;
                    }else if(arr_char[j]=='O'&&arr_char[j-1]=='X'){
                        arr_int[j] = 1;
                    }
                }else{
                    if(arr_char[0]=='O') arr_int[0] = 1;
                }
                sum += arr_int[j];
            }
            System.out.println(sum);
        }
    }
}