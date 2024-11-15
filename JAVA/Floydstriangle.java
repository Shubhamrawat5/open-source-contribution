
import java.util.*;

public class Floydstriangle {
    public static void main(String[] args) {
        int n = 5;
        int m = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j <= i) {
                    System.out.print(m + " ");
                    m++;
                } else {
                    System.out.print("");
                }

            }
            System.out.println();
        }
    }
}
