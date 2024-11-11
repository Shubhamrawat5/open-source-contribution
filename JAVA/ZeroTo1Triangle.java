
import java.util.*;

public class ZeroTo1Triangle {
    public static void main(String[] args) {
        int l = 5;
        for (int i = 0; i <= l; i++) {
            for (int j = 1; j <= l; j++) {
                if (j <= i) {
                    int a;
                    a = j;
                    a = a % 2;
                    System.out.print(a);
                } else {
                    System.out.print(" ");
                }
            }

            System.out.println();
        }
    }
}