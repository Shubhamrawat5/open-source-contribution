
//This code tell us what is the bit present at a particular position of number in binary system
import java.util.*;

public class BitMan {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number : ");
        int no = sc.nextInt();
        System.out.print("Enter the postion : ");
        int pos = sc.nextInt();
        int bitMask = 1 << pos;

        if ((bitMask & no) == 0) {
            System.out.println("bit was zero");
        } else

        {
            System.out.println("bit was 1");
        }
    }
}
