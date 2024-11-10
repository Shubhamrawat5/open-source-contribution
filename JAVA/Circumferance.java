import java.util.Scanner;

public class Circumferance {

    public static double circle(float r) {
        double circum = 2 * 3.14 * r;
        System.out.println("your circumfer" + circum);
        return circum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        float r = sc.nextFloat();
        circle(r);
    }
}
