import java.util.*;

public class ProductCalculator {
    public static int productCal(int a, int b) {
        int product = a * b;
        return product;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int product = productCal(a, b);
        System.out.println(product);
    }
}
