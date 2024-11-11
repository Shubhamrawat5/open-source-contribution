
//this code set the bit position given by the user to "1"
import java.util.*;

public class SetBit {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number:");
        int no = sc.nextInt();
        System.out.print("Enter the position to change the bit:");
        int pos = sc.nextInt();
        int bitMass = 1 << pos;
        int newno = bitMass | no;
        System.out.println("Your Final no.:" + newno);
    }

}