import java.util.*;

public class GCD {
    public static void GCD(int a, int b) {
        if (a % b == 0) {
            System.out.println("The GCD : " + b);
        } else {
            if (b % a == 0) {
                System.out.println("The GCD : " + a);
            } else {
                if (a != b) {
                    if (a > b) {
                        a = a - b;
                        System.out.println("The GCD : " + a);
                    } else {
                        if (b > a) {
                            b = b - a;
                            System.out.println("The GCD : " + b + b);
                        }
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        GCD(a, b);
    }
}