
//This code clears or sets a bit value to "0" at a particular position given by user 
import java.util.*;

public class ClearBit {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your number : ");
        int no = sc.nextInt();
        System.out.print("Enter the bit postion you want to clear : ");
        int pos = sc.nextInt();
        int bitMass = 1 << pos;
        int notbitMass = ~bitMass;
        int newnumber = notbitMass & no;
        System.out.print("Your Final no. : " + newnumber);
    }
}
