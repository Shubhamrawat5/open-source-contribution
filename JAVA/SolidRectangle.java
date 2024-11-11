import java.util.*;

public class SolidRectangle {
    public static void main(String[] args) {
        int b = 4;
        int l = 5;

        for (int i = 1; i <= b; i++) {
            for (int j = 1; j <= l; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
