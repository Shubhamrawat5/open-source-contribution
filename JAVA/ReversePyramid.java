
import java.util.*;

public class ReversePyramid {
    public static void main(String[] args) {
        int l = 4;
        int b = 4;
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= b; j++) {
                if (i <= j) {
                    System.out.print("*");
                }
                System.out.print(" ");
            }
            System.out.println();
        }
    }
}