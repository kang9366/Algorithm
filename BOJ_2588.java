import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int first = sc.nextInt();
        int second = sc.nextInt();
        int a = second / 100;
        int b = (second-a*100) / 10;
        int c = second-a*100-b*10;

        System.out.println(first*c);
        System.out.println(first*b);
        System.out.println(first*a);
        System.out.println(first*c + first*b*10 + first*a*100);
    }
}