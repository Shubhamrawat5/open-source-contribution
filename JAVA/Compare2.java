import java.util.*;

public class Compare2 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        if (a == b) {
            System.out.println("both are equal");
        } else {
            if (a >= b) {
                System.out.println("a is greater then b");
            } else {
                System.out.println("b is greater then a");
            }
        }
    }
}
