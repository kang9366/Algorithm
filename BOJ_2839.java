import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int a = (N/5) + ((N%5)/3);
        if(N%5==0){
            System.out.println(N/5);
        }else if(N%3==0){
            if((N%5)%3==0){
                if(N/3 < a) System.out.println(N/3);
                else System.out.println(a);
            }else{
                System.out.println(N/3);
            }
        }else{
            if((N%5)%3==0){
                System.out.println(a);
            }else{
                System.out.println(-1);
            }
        }
    }
}
