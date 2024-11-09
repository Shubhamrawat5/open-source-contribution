import java.util.*;

public class Average {
    public static void averg(int a, int b, int c) {
        int avg = (a + b + c) / 3;
        System.out.println(avg);
        return;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        averg(a, b, c);
    }
}
